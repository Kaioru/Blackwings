// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>

extern "C" __declspec(dllexport) VOID NoOp() {}

BOOL APIENTRY DllMain( 
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH: {
            BOOL bAlloc = AllocConsole();

            if (bAlloc) {
                SetConsoleTitleA("Hello");

                FILE* file = nullptr;

                freopen_s(&file, "CONIN$", "r", stdin);
                freopen_s(&file, "CONOUT$", "w", stdout);
                freopen_s(&file, "CONOUT$", "w", stderr);
            }
            break;
        }
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

