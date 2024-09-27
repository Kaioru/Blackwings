#include "pch.h"

LPVOID Memory::AddressOf(LPCSTR sModule, LPCSTR sProc)
{
    HMODULE hModule;

    if (hModule = GetModuleHandleA(sModule); hModule == NULL)
        hModule = LoadLibraryA(sModule);

    if (hModule == NULL) 
    {
        SPDLOG_DEBUG("Could not resolve module %s", sModule);
        return (LPVOID)0;
    }

    FARPROC hProc = GetProcAddress(hModule, sProc);

    if (hProc == NULL)
    {
        SPDLOG_DEBUG("Could not resolve module %s %s", sModule, sProc);
        return (LPVOID)0;
    }
    return (LPVOID)hProc;
}

template void Memory::Read<BYTE>(DWORD, BYTE*);
template void Memory::Read<SHORT>(DWORD, SHORT*);
template void Memory::Read<INT>(DWORD, INT*);
template void Memory::Read<LONG>(DWORD, LONG*);
template <typename T>
VOID Memory::Read(DWORD dwAddress, T* value)
{
    value = ((T*)dwAddress);
}

template void Memory::Write<BYTE>(DWORD, BYTE);
template void Memory::Write<SHORT>(DWORD, SHORT);
template void Memory::Write<INT>(DWORD, INT);
template void Memory::Write<LONG>(DWORD, LONG);
template <typename T>
VOID Memory::Write(DWORD dwAddress, T value)
{
    DWORD dwProtect;

    VirtualProtect((LPVOID)dwAddress, sizeof(T), PAGE_EXECUTE_READWRITE, &dwProtect);

    *((T*)dwAddress) = value;

    VirtualProtect((LPVOID)dwAddress, sizeof(T), dwProtect, &dwProtect);
}

VOID Memory::WriteFill(DWORD dwAddress, BYTE cValue, SIZE_T nSize)
{
    DWORD dwProtect;

    VirtualProtect((LPVOID)dwAddress, nSize, PAGE_EXECUTE_READWRITE, &dwProtect);
    memset((void*)dwAddress, cValue, nSize);
    VirtualProtect((LPVOID)dwAddress, nSize, dwProtect, &dwProtect);
}

BOOL Memory::Trampoline(LPVOID* ppTarget, LPVOID pDetour)
{
    LONG nResult;

    if (nResult = DetourTransactionBegin(); nResult != NO_ERROR) {
        SPDLOG_DEBUG("Trampoline transaction begin failed with %d", nResult);
        return FALSE;
    }

    if (nResult = DetourUpdateThread(GetCurrentThread()); nResult != NO_ERROR) {
        SPDLOG_DEBUG("Trampoline update thread failed with %d", nResult);
        return FALSE;
    }

    if (nResult = DetourAttach(ppTarget, pDetour); nResult != NO_ERROR) {
        SPDLOG_DEBUG("Trampoline attach failed with %d", nResult);
        return FALSE;
    }

    if (nResult = DetourTransactionCommit(); nResult != NO_ERROR) {
        SPDLOG_DEBUG("Trampoline transaction commit failed with %d", nResult);
        return FALSE;
    }

    return TRUE;
}