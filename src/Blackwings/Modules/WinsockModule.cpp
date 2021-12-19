#include <winsock2.h>
#include <WS2spi.h>
#include "detours/detours.h"

#include "../Config.h"
#include "WinsockModule.h"

BOOL bInit = false;

sockaddr_in dwHostAddress;
sockaddr_in dwRouteAddress;

LPWSPSTARTUP lpWPStartup_O;
LPWSPCONNECT lpWSPConnect_O;
LPWSPGETPEERNAME lpWSPGetPeerName_O;

int WINAPI WSPConnect_H(SOCKET s, const struct sockaddr* name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS, LPINT lpErrno)
{
    auto sAddr = (sockaddr_in*)name;

    if (!bInit) {
        dwHostAddress = *sAddr;

        sAddr->sin_addr.S_un.S_addr = inet_addr(Config::Host.c_str());
        sAddr->sin_port = htons(Config::Port);

        dwRouteAddress = *sAddr;
        bInit = true;
    }

    return lpWSPConnect_O(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS, lpErrno);
}

int WINAPI WSPGetPeerName_H(SOCKET s, struct sockaddr* name, LPINT namelen, LPINT lpErrno)
{
    int nResult = lpWSPGetPeerName_O(s, name, namelen, lpErrno);

    if (nResult == 0) {
        auto sAddr = (sockaddr_in*)name;

        sAddr->sin_addr.S_un.S_addr = dwHostAddress.sin_addr.S_un.S_addr;
        sAddr->sin_port = dwHostAddress.sin_port;
    }

    return nResult;
}

int WINAPI WSPStartup_H(WORD wVersionRequested, LPWSPDATA lpWSPData, LPWSAPROTOCOL_INFOW lpProtocolInfo, WSPUPCALLTABLE UpcallTable, LPWSPPROC_TABLE lpProcTable)
{
    int nResult = lpWPStartup_O(wVersionRequested, lpWSPData, lpProtocolInfo, UpcallTable, lpProcTable);

    if (nResult == 0) {
        lpWSPConnect_O = lpProcTable->lpWSPConnect;
        lpWSPGetPeerName_O = lpProcTable->lpWSPGetPeerName;

        lpProcTable->lpWSPConnect = WSPConnect_H;
        lpProcTable->lpWSPGetPeerName = WSPGetPeerName_H;
    }

    return nResult;
}

void WinsockModule::Attach() {
    HMODULE hModule = LoadLibrary("MSWSOCK");

    if (hModule) {
        lpWPStartup_O = (LPWSPSTARTUP)GetProcAddress(hModule, "WSPStartup");

        if (!lpWPStartup_O) return;

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach((PVOID*)&lpWPStartup_O, (PVOID)WSPStartup_H);
        DetourTransactionCommit();
    }
}

void WinsockModule::Detach() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach((PVOID*)&lpWPStartup_O, (PVOID)WSPStartup_H);
    DetourTransactionCommit();
}