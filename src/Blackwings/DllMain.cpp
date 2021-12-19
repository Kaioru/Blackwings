#include <windows.h>
#include "detours/detours.h"

#include "Modules/WindowModule.h"
#include "Modules/WinsockModule.h"
#include "Config.h"

extern "C" __declspec(dllexport) void NoOp() {}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    DisableThreadLibraryCalls(hModule);

    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        Config::Initialize();

        WindowModule::Attach();
        WinsockModule::Attach();
    }

    if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        WindowModule::Detach();
        WinsockModule::Detach();
    }

    return TRUE;
}