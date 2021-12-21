#include <windows.h>
#include "Memory.h"

template void Memory::Read<char>(DWORD, char*);
template void Memory::Read<short>(DWORD, short*);
template void Memory::Read<int>(DWORD, int*);
template void Memory::Read<long>(DWORD, long*);
template void Memory::Read<float>(DWORD, float*);
template void Memory::Read<double>(DWORD, double*);

template void Memory::Write<char>(DWORD, char);
template void Memory::Write<short>(DWORD, short);
template void Memory::Write<int>(DWORD, int);
template void Memory::Write<long>(DWORD, long);
template void Memory::Write<float>(DWORD, float);
template void Memory::Write<double>(DWORD, double);

template <typename T>
void Memory::Read(DWORD dwAddress, T* value) {
    value = ((T*)dwAddress);
}

template <typename T>
void Memory::Write(DWORD dwAddress, T value) {
    DWORD dwProtect;

    VirtualProtect((LPVOID)dwAddress, sizeof(T), PAGE_EXECUTE_READWRITE, &dwProtect);

    *((T*)dwAddress) = value;

    VirtualProtect((LPVOID)dwAddress, sizeof(T), dwProtect, &dwProtect);
}
