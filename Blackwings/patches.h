#pragma once

class Patches {
public:
    static VOID PatchWinAPI();
    static VOID PatchWinSock();

    static VOID PatchGameLogoSkip();
    static VOID PatchGameWindowUI();
    static VOID PatchGameWindowSizing();
};
