// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>

#define TITLE "Blackwings"

extern "C" __declspec(dllexport) VOID NoOp() {}

BOOL APIENTRY DllMain( 
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH: {

#ifdef _DEBUG
            BOOL bAlloc = AllocConsole();

            if (bAlloc) {
                SetConsoleTitleA(fmt::format("{} (PID: {})", TITLE, GetCurrentProcessId()).c_str());

                FILE* file = nullptr;

                freopen_s(&file, "CONIN$", "r", stdin);
                freopen_s(&file, "CONOUT$", "w", stdout);
                freopen_s(&file, "CONOUT$", "w", stderr);
            }
#endif

            Patches::PatchWinSock();
            Patches::PatchWinAPI();

            OutputDebugStringA("DONE");
            break;
        }
    }

    return TRUE;
}

