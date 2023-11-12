#include "pch.h"

VOID Game::OnGameInit() 
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    Patches::PatchWinAPI();
    Patches::PatchWinSock();

    DetourTransactionCommit();
}

VOID Game::OnGameStart()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    if (Config::GameLogoSkip)
        Patches::PatchGameLogoSkip();
    if (Config::GameWindowSizing)
        Patches::PatchGameWindowSizing();

    DetourTransactionCommit();
}
