#include <windows.h>
#include "detours/detours.h"

#include "INetMsgHandlerModule.h"
#include "../Game/Addresses.h"
#include "../Config.h"

typedef void(__fastcall* pCLogin__OnPacket)(void* pThis, void* edx, int nType, void* iPacket);
typedef void(__fastcall* pCField__OnPacket)(void* pThis, void* edx, int nType, void* iPacket);
typedef void(__fastcall* pCCashShop__OnPacket)(void* pThis, void* edx, int nType, void* iPacket);
typedef void(__fastcall* pCITC__OnPacket)(void* pThis, void* edx, int nType, void* iPacket);
typedef void(__fastcall* pCWvsContext__OnPacket)(void* pThis, void* edx, int nType, void* iPacket);

auto oCLogin__OnPacket = reinterpret_cast<pCLogin__OnPacket>(ADDR_CLOGIN__ONPACKET);
auto oCField__OnPacket = reinterpret_cast<pCField__OnPacket>(ADDR_CFIELD__ONPACKET);
auto oCCashShop__OnPacket = reinterpret_cast<pCCashShop__OnPacket>(ADDR_CCASHSHOP__ONPACKET);
auto oCITC__OnPacket = reinterpret_cast<pCITC__OnPacket>(ADDR_CITC__ONPACKET);
auto oCWvsContext__OnPacket = reinterpret_cast<pCWvsContext__OnPacket>(ADDR_CWVSCONTEXT__ONPACKET);

bool OnPacket(int nType, void* iPacket) {
    switch (nType) {
    default:
        return false;
    }

    return true;
}

void __fastcall hkCLogin__OnPacket(void* pThis, void* edx, int nType, void* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    oCLogin__OnPacket(pThis, edx, nType, iPacket);
}

void __fastcall hkCField__OnPacket(void* pThis, void* edx, int nType, void* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    oCField__OnPacket(pThis, edx, nType, iPacket);
}

void __fastcall hkCCashShop__OnPacket(void* pThis, void* edx, int nType, void* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    oCCashShop__OnPacket(pThis, edx, nType, iPacket);
}

void __fastcall hkCITC__OnPacket(void* pThis, void* edx, int nType, void* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    oCITC__OnPacket(pThis, edx, nType, iPacket);
}

void __fastcall hkCWvsContext__OnPacket(void* pThis, void* edx, int nType, void* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    oCWvsContext__OnPacket(pThis, edx, nType, iPacket);
}

void INetMsgHandlerModule::Attach() {
    DetourAttach((PVOID*)&oCLogin__OnPacket, (PVOID)hkCLogin__OnPacket);
    DetourAttach((PVOID*)&oCField__OnPacket, (PVOID)hkCField__OnPacket);
    DetourAttach((PVOID*)&oCCashShop__OnPacket, (PVOID)hkCCashShop__OnPacket);
    DetourAttach((PVOID*)&oCITC__OnPacket, (PVOID)hkCITC__OnPacket);
    DetourAttach((PVOID*)&oCWvsContext__OnPacket, (PVOID)hkCWvsContext__OnPacket);
}

void INetMsgHandlerModule::Detach() {
    DetourDetach((PVOID*)&oCLogin__OnPacket, (PVOID)hkCLogin__OnPacket);
    DetourDetach((PVOID*)&oCField__OnPacket, (PVOID)hkCField__OnPacket);
    DetourDetach((PVOID*)&oCCashShop__OnPacket, (PVOID)hkCCashShop__OnPacket);
    DetourDetach((PVOID*)&oCITC__OnPacket, (PVOID)hkCITC__OnPacket);
    DetourDetach((PVOID*)&oCWvsContext__OnPacket, (PVOID)hkCWvsContext__OnPacket);
}
