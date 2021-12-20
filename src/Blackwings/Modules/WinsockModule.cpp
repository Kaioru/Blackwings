#include <winsock2.h>
#include <WS2spi.h>
#include "detours/detours.h"

#include "../Config.h"
#include "WinsockModule.h"

BOOL bInit = false;

sockaddr_in dwHostAddress;
sockaddr_in dwRouteAddress;

LPWSPSTARTUP        lpWPStartup;
LPWSPCONNECT        lpWSPConnect;
LPWSPGETPEERNAME    lpWSPGetPeerName;

int WINAPI hkWSPConnect(SOCKET s, const struct sockaddr* name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS, LPINT lpErrno)
{
    auto sAddr = (sockaddr_in*)name;

    if (!bInit) {
        dwHostAddress = *sAddr;

        sAddr->sin_addr.S_un.S_addr = inet_addr(Config::Connection.Host.c_str());
        sAddr->sin_port = htons(Config::Connection.Port);

        dwRouteAddress = *sAddr;
        bInit = true;
    }

    return lpWSPConnect(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS, lpErrno);
}

int WINAPI hkWSPGetPeerName(SOCKET s, struct sockaddr* name, LPINT namelen, LPINT lpErrno)
{
    int nResult = lpWSPGetPeerName(s, name, namelen, lpErrno);

    if (nResult == 0) {
        auto sAddr = (sockaddr_in*)name;

        sAddr->sin_addr.S_un.S_addr = dwHostAddress.sin_addr.S_un.S_addr;
        sAddr->sin_port = dwHostAddress.sin_port;
    }

    return nResult;
}

int WINAPI hkWSPStartup(WORD wVersionRequested, LPWSPDATA lpWSPData, LPWSAPROTOCOL_INFOW lpProtocolInfo, WSPUPCALLTABLE UpcallTable, LPWSPPROC_TABLE lpProcTable)
{
    int nResult = lpWPStartup(wVersionRequested, lpWSPData, lpProtocolInfo, UpcallTable, lpProcTable);

    if (nResult == 0) {
        lpWSPConnect = lpProcTable->lpWSPConnect;
        lpWSPGetPeerName = lpProcTable->lpWSPGetPeerName;

        lpProcTable->lpWSPConnect = hkWSPConnect;
        lpProcTable->lpWSPGetPeerName = hkWSPGetPeerName;
    }

    return nResult;
}

void WinsockModule::Attach() {
    HMODULE hModule = LoadLibrary("MSWSOCK");

    if (hModule) {
        lpWPStartup = (LPWSPSTARTUP)GetProcAddress(hModule, "WSPStartup");

        if (!lpWPStartup) return;

        DetourAttach((PVOID*)&lpWPStartup, (PVOID)hkWSPStartup);
    }
}

void WinsockModule::Detach() {
    DetourDetach((PVOID*)&lpWPStartup, (PVOID)hkWSPStartup);
}
