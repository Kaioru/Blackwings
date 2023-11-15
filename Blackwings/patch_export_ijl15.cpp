#include "pch.h"

FARPROC pIjlGetLibVersion;
FARPROC pIjlInit;
FARPROC pIjlFree;
FARPROC pIjlRead;
FARPROC pIjlWrite;
FARPROC pIjlErrorStr;

VOID Patches::PatchExportIjl15() 
{
    HMODULE hModule = LoadLibraryA("ijl15_orig.dll");

    if (hModule == NULL) {
        MessageBoxA(NULL, "Failed to find ijl15_orig.dll file", "File not found", 0);
        ExitProcess(0);
        return;
    }

    pIjlGetLibVersion = GetProcAddress(hModule, "ijlGetLibVersion");
    pIjlInit = GetProcAddress(hModule, "ijlInit");
    pIjlFree = GetProcAddress(hModule, "ijlFree");
    pIjlRead = GetProcAddress(hModule, "ijlRead");
    pIjlWrite = GetProcAddress(hModule, "ijlWrite");
    pIjlErrorStr = GetProcAddress(hModule, "ijlErrorStr");
}

extern "C" __declspec(dllexport) __declspec(naked) void ijlGetLibVersion()
{
    __asm jmp dword ptr[pIjlGetLibVersion]
}

extern "C" __declspec(dllexport) __declspec(naked) void ijlInit()
{
    __asm jmp dword ptr[pIjlInit]
}

extern "C" __declspec(dllexport) __declspec(naked) void ijlFree()
{
    __asm jmp dword ptr[pIjlFree]
}

extern "C" __declspec(dllexport) __declspec(naked) void ijlRead()
{
    __asm jmp dword ptr[pIjlRead]
}

extern "C" __declspec(dllexport) __declspec(naked) void ijlWrite()
{
    __asm jmp dword ptr[pIjlWrite]
}

extern "C" __declspec(dllexport) __declspec(naked) void ijlErrorStr()
{
    __asm jmp dword ptr[pIjlErrorStr]
}
