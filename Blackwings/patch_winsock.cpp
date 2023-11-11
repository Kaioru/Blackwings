#include "pch.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <WS2spi.h>

BOOL bInit = false;

sockaddr_in dwHostAddress;
sockaddr_in dwRouteAddress;

LPWSPSTARTUP        orig_WSPStartup;
LPWSPCONNECT        orig_WSPConnect;
LPWSPGETPEERNAME    orig_WSPGetPeerName;

INT WINAPI hook_WSPConnect(
    SOCKET s,
    const struct sockaddr* name,
    INT namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    LPINT lpErrno
)
{
    auto sAddr = (sockaddr_in*)name;

    if (!bInit || sAddr->sin_addr.S_un.S_addr == dwHostAddress.sin_addr.S_un.S_addr) {
        dwHostAddress = *sAddr;

        sAddr->sin_addr.S_un.S_addr = inet_addr(Config::ConnectionHost);
        sAddr->sin_port = htons(Config::ConnectionPort);

        dwRouteAddress = *sAddr;
        bInit = true;
    }

    return orig_WSPConnect(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS, lpErrno);
}

INT WINAPI hook_WSPGetPeerName(
    SOCKET s,
    struct sockaddr* name,
    LPINT namelen,
    LPINT lpErrno
)
{
    auto nResult = orig_WSPGetPeerName(s, name, namelen, lpErrno);

    if (nResult == 0) {
        auto sAddr = (sockaddr_in*)name;

        sAddr->sin_addr.S_un.S_addr = dwHostAddress.sin_addr.S_un.S_addr;
        sAddr->sin_port = dwHostAddress.sin_port;
    }

    return nResult;
}

INT WINAPI hook_WSPStartup(
    WORD                wVersionRequested,
    LPWSPDATA           lpWSPData,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    WSPUPCALLTABLE      UpcallTable,
    LPWSPPROC_TABLE     lpProcTable
)
{
    auto nResult = orig_WSPStartup(wVersionRequested, lpWSPData, lpProtocolInfo, UpcallTable, lpProcTable);

    if (nResult == 0) {
        orig_WSPConnect = lpProcTable->lpWSPConnect;
        orig_WSPGetPeerName = lpProcTable->lpWSPGetPeerName;

        lpProcTable->lpWSPConnect = hook_WSPConnect;
        lpProcTable->lpWSPGetPeerName = hook_WSPGetPeerName;
    }

    return nResult;
}

VOID Patches::PatchWinSock()
{
    auto hModule = LoadLibraryA("MSWSOCK");

    if (!hModule) return;

    orig_WSPStartup = (LPWSPSTARTUP)GetProcAddress(hModule, "WSPStartup");

    if (!orig_WSPStartup) return;

    DetourAttach((PVOID*)&orig_WSPStartup, (PVOID)hook_WSPStartup);
}
