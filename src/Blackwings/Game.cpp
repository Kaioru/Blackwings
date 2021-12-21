#include <windows.h>
#include "detours/detours.h"
#include "Game.h"

#include "Game/Shared/ZXString.h"
#include "Modules/StringPoolModule.h"
#include "Modules/INetMsgHandlerModule.h"
#include "Modules/GameMemoryModule.h"
#include "Config.h"

bool bStarted = false;

void Game::OnGameStart() {
    if (bStarted) return;

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    StringPoolModule::Initialize();
    StringPoolModule::Attach();

    INetMsgHandlerModule::Attach();

    DetourTransactionCommit();

    bStarted = true;

}

void Game::OnGameEnd() {
    if (!bStarted) return;

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    StringPoolModule::Detach();
    INetMsgHandlerModule::Detach();

    DetourTransactionCommit();

    bStarted = false;
}
