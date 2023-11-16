#pragma once

class Patches {
public:
    static VOID PatchWinAPI();
    static VOID PatchWinSock();

    static VOID PatchGameLogoSkip();
    static VOID PatchGameWindowImGui();
    static VOID PatchGameWindowSizing();

    static VOID PatchGameResManInitialize();
    static VOID PatchGameResManCustomOverrides();

    static VOID PatchGameInputJoystickDisable();

    static VOID PatchExportIjl15();
};
