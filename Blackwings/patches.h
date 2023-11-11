#pragma once

class Patches {
public:
    static VOID PatchWinAPI();
    static VOID PatchWinSock();

    static VOID PatchGameWindowSizing();
};
