#pragma once

class Patches {
public:
    static VOID PatchWinAPI();
    static VOID PatchWinSock();

#ifdef _DEBUG
    static VOID PatchGameLogging();
#endif

    static VOID PatchGameLogoSkip();
    static VOID PatchGameWindowImGui();
    static VOID PatchGameWindowSizing();
    static VOID PatchGameResManFileSystem();
    static VOID PatchGameInputJoystickDisable();
};
