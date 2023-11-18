#include "pch.h"

using T_OnPacket = VOID(_fastcall*)(PVOID pThis, PVOID edx, int nType, CInPacket* iPacket);

auto orig_CLogin__OnPacket      = reinterpret_cast<T_OnPacket>(0x005DF940);
auto orig_CField__OnPacket      = reinterpret_cast<T_OnPacket>(0x00546D50);
auto orig_CCashShop__OnPacket   = reinterpret_cast<T_OnPacket>(0x004997E0);
auto orig_CITC__OnPacket        = reinterpret_cast<T_OnPacket>(0x00577470);
auto orig_CWvsContext__OnPacket = reinterpret_cast<T_OnPacket>(0x009E5830);

bool OnPacket(int nType, CInPacket* iPacket) {
    SPDLOG_INFO("Packet type: {}", nType);
    
    // TODO: Handle custom packets here
    /* Example packet sending
        if (nType == 0) {
            auto oPacket = new COutPacket(0x1337);

            oPacket->Encode4(0x1337);
            oPacket->SendPacket();
            return false;
        }
    */

    if (Config::GameNetMsgCustomProtocol) {
        switch ((BWRecvOps)nType) {
        case BWRecv_Read: {
            auto address = iPacket->Decode4();
            auto dataType = iPacket->Decode1();
            auto oPacket = COutPacket(BWSend_ReadRes);

            oPacket.Encode4(address);
            oPacket.Encode1(dataType);

            switch (dataType) {
            case 0: {
                BYTE value;
                Memory::Read<BYTE>(address, &value);
                oPacket.Encode1(value);
                break;
            }
            case 1: {
                SHORT value;
                Memory::Read<SHORT>(address, &value);
                oPacket.Encode2(value);
                break;
            }
            case 2: {
                INT value;
                Memory::Read<INT>(address, &value);
                oPacket.Encode4(value);
                break;
            }
            case 3:
                // TODO
                break;
            }
            break;
        }
        case BWRecv_Write: {
            auto address = iPacket->Decode4();
            auto dataType = iPacket->Decode1();

            switch (dataType) {
            case 0:
                Memory::Write<BYTE>(address, iPacket->Decode1());
                break;
            case 1:
                Memory::Write<SHORT>(address, iPacket->Decode2());
                break;
            case 2:
                Memory::Write<INT>(address, iPacket->Decode4());
                break;
            case 3:
                // TODO
                break;
            }
            break;
        }
        default:
            return false;
        }

        return true;
    }

    return false;
}

VOID _fastcall hook_CLogin__OnPacket(PVOID pThis, PVOID edx, int nType, CInPacket* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    orig_CLogin__OnPacket(pThis, edx, nType, iPacket);
}

VOID _fastcall hook_CField__OnPacket(PVOID pThis, PVOID edx, int nType, CInPacket* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    orig_CField__OnPacket(pThis, edx, nType, iPacket);
}

VOID _fastcall hook_CCashShop__OnPacket(PVOID pThis, PVOID edx, int nType, CInPacket* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    orig_CCashShop__OnPacket(pThis, edx, nType, iPacket);
}

VOID _fastcall hook_CITC__OnPacket(PVOID pThis, PVOID edx, int nType, CInPacket* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    orig_CITC__OnPacket(pThis, edx, nType, iPacket);
}

VOID _fastcall hook_CWvsContext__OnPacket(PVOID pThis, PVOID edx, int nType, CInPacket* iPacket) {
    if (OnPacket(nType, iPacket)) return;
    orig_CWvsContext__OnPacket(pThis, edx, nType, iPacket);
}

VOID Patches::PatchGameNetMsgCustom()
{
    DetourAttach((PVOID*)&orig_CLogin__OnPacket, (PVOID)hook_CLogin__OnPacket);
    DetourAttach((PVOID*)&orig_CField__OnPacket, (PVOID)hook_CField__OnPacket);
    DetourAttach((PVOID*)&orig_CCashShop__OnPacket, (PVOID)hook_CCashShop__OnPacket);
    DetourAttach((PVOID*)&orig_CITC__OnPacket, (PVOID)hook_CITC__OnPacket);
    DetourAttach((PVOID*)&orig_CWvsContext__OnPacket, (PVOID)hook_CWvsContext__OnPacket);
}
