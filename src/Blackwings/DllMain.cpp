#include <windows.h>
#include "detours/detours.h"

#include "Game/StringPool.h"
#include "Modules/WindowModule.h"
#include "Modules/WinsockModule.h"
#include "Modules/StringPoolModule.h"
#include "Modules/INetMsgHandlerModule.h"
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

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        WindowModule::Attach();
        WinsockModule::Attach();

        StringPoolModule::Initialize();
        StringPoolModule::Attach();

        INetMsgHandlerModule::Attach();

        DetourTransactionCommit();
    }
    
    if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        WindowModule::Detach();
        WinsockModule::Detach();
        StringPoolModule::Detach();
        INetMsgHandlerModule::Detach();

        DetourTransactionCommit();
    }
    
    return TRUE;
}
