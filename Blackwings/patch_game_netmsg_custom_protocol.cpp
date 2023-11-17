#include "pch.h"

using T_CWvsApp__ConnectLogin = VOID(_fastcall*)(PVOID pThis, PVOID edx);

auto orig_CWvsApp__ConnectLogin = reinterpret_cast<T_CWvsApp__ConnectLogin>(0x009C1B30);

VOID _fastcall hook_CWvsApp__ConnectLogin(PVOID pThis, PVOID edx)
{
    orig_CWvsApp__ConnectLogin(pThis, edx);
    (new COutPacket(BHSend_Init))->SendPacket();
}

VOID Patches::PatchGameNetMsgCustomProtocol() 
{
    DetourAttach((PVOID*)&orig_CWvsApp__ConnectLogin, (PVOID)hook_CWvsApp__ConnectLogin);
}
