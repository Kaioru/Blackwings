#include "pch.h"

typedef HWND(WINAPI* LPCREATEWINDOWEXA)(
    DWORD     dwExStyle,
    LPCSTR    lpClassName,
    LPCSTR    lpWindowName,
    DWORD     dwStyle,
    int       X,
    int       Y,
    int       nWidth,
    int       nHeight,
    HWND      hWndParent,
    HMENU     hMenu,
    HINSTANCE hInstance,
    LPVOID    lpParam
    );

LPCREATEWINDOWEXA orig_CreateWindowExA;

HWND hook_CreateWindowExA(
    DWORD     dwExStyle,
    LPCSTR    lpClassName,
    LPCSTR    lpWindowName,
    DWORD     dwStyle,
    int       X,
    int       Y,
    int       nWidth,
    int       nHeight,
    HWND      hWndParent,
    HMENU     hMenu,
    HINSTANCE hInstance,
    LPVOID    lpParam
)
{
    if (!strcmp(lpClassName, "MapleStoryClass")) {
        lpWindowName = Config::GameTitle;

        Game::OnGameStart();
    }

    return orig_CreateWindowExA(
        dwExStyle,
        lpClassName,
        lpWindowName,
        dwStyle,
        X,
        Y,
        nWidth,
        nHeight,
        hWndParent,
        hMenu,
        hInstance,
        lpParam
    );
}

VOID Hooks::HookWinAPI()
{
    auto hModule = LoadLibraryA("USER32");

    if (!hModule) return;

    orig_CreateWindowExA = (LPCREATEWINDOWEXA)GetProcAddress(hModule, "CreateWindowExA");

    if (!orig_CreateWindowExA) return;

    DetourAttach((PVOID*)&orig_CreateWindowExA, (PVOID)hook_CreateWindowExA);
}
