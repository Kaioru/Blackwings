#include "pch.h"
#include <winsock2.h>
#include <WS2spi.h>
#include <ws2tcpip.h>

const PCSTR ADDRESS_SERVER = "127.0.0.1";
const PCSTR ADDRESS_SPOOF = "63.251.217.1";

LPWSPCONNECT        WSPConnect_orig;
LPWSPCONNECT		WSPConnect_hook = [](
	SOCKET s,
	const sockaddr* name,
	int namelen,
	LPWSABUF lpCallerData,
	LPWSABUF lpCalleeData,
	LPQOS lpSQOS,
	LPQOS lpGQOS,
	LPINT lpErrno
	) -> INT {
		sockaddr_in* sin = (sockaddr_in*)name;

		InetPtonA(AF_INET, ADDRESS_SERVER, &sin->sin_addr.S_un.S_addr);
		return WSPConnect_orig(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS, lpErrno);
	};

LPWSPGETPEERNAME    WSPGetPeerName_orig;
LPWSPGETPEERNAME	WSPGetPeerName_hook = [](
	SOCKET s,
	sockaddr* name,
	LPINT namelen,
	LPINT lpErrno
	) -> INT {
		INT result = WSPGetPeerName_orig(s, name, namelen, lpErrno);
		sockaddr_in* sin = (sockaddr_in*)name;

		InetPtonA(AF_INET, ADDRESS_SPOOF, &sin->sin_addr.S_un.S_addr);
		return result;
	};

LPWSPSTARTUP        WSPStartup_orig = (LPWSPSTARTUP)Memory::AddressOf("MSWSOCK", "WSPStartup");
LPWSPSTARTUP        WSPStartup_hook = [](
	WORD wVersionRequested,
	LPWSPDATA lpWSPData,
	LPWSAPROTOCOL_INFOW lpProtocolInfo,
	WSPUPCALLTABLE UpcallTable,
	LPWSPPROC_TABLE lpProcTable
	) -> INT {
		INT result = WSPStartup_orig(wVersionRequested, lpWSPData, lpProtocolInfo, UpcallTable, lpProcTable);

		WSPConnect_orig = lpProcTable->lpWSPConnect;
		WSPGetPeerName_orig = lpProcTable->lpWSPGetPeerName;
		lpProcTable->lpWSPConnect = WSPConnect_hook;
		lpProcTable->lpWSPGetPeerName = WSPGetPeerName_hook;
		return result;
	};

VOID Patches::PatchWinSock()
{
	Memory::Trampoline((PVOID*)&WSPStartup_orig, (PVOID)WSPStartup_hook);
}