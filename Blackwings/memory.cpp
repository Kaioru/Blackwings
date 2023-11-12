#include "pch.h"

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

void Memory::WriteFill(DWORD dwAddress, BYTE cValue, SIZE_T nSize)
{
    DWORD dwProtect;

    VirtualProtect((LPVOID)dwAddress, nSize, PAGE_EXECUTE_READWRITE, &dwProtect);
    memset((void*)dwAddress, cValue, nSize);
    VirtualProtect((LPVOID)dwAddress, nSize, dwProtect, &dwProtect);
}
