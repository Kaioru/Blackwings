#include <windows.h>
#include "detours/detours.h"

#include "../Game.h"
#include "../Config.h"
#include "WinAPIModule.h"

typedef HWND(WINAPI* pCreateWindowExA)(
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

pCreateWindowExA oCreateWindowExA;

HWND hkCreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) {
    if (!strcmp(lpClassName, "MapleStoryClass")) {
        lpWindowName = Config::Game.Title.c_str();

        Game::OnGameStart();
    }

    return oCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

void WinAPIModule::Attach() {
    HMODULE hModule = LoadLibrary("USER32");

    if (hModule) {
        oCreateWindowExA = (pCreateWindowExA)GetProcAddress(hModule, "CreateWindowExA");

        if (!oCreateWindowExA) return;

        DetourAttach((PVOID*)&oCreateWindowExA, (PVOID)hkCreateWindowExA);
    }
}

void WinAPIModule::Detach() {
    DetourDetach((PVOID*)&oCreateWindowExA, (PVOID)hkCreateWindowExA);
}
