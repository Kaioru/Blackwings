#pragma once

class Hooks {
public:
    static VOID HookWinAPI();
    static VOID HookWinSock();

    static VOID HookGameResolution();
};
