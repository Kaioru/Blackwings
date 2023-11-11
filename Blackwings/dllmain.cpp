#include "pch.h"

extern "C" __declspec(dllexport) VOID NoOp() {}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD   ul_reason_for_call,
    LPVOID  lpReserved
)
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            Config::Read();
            Game::OnGameInit();
            break;
        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}

