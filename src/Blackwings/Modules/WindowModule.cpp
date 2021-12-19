#include <windows.h>
#include "detours/detours.h"

#include "../Config.h"
#include "WindowModule.h"

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
	lpWindowName = Config::Game.Title.c_str();
	
	return oCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

void WindowModule::Attach() {
	HMODULE hModule = LoadLibrary("USER32");

	if (hModule) {
		oCreateWindowExA = (pCreateWindowExA)GetProcAddress(hModule, "CreateWindowExA");

		if (!oCreateWindowExA) return;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach((PVOID*)&oCreateWindowExA, (PVOID)hkCreateWindowExA);
		DetourTransactionCommit();
	}
}

void WindowModule::Detach() {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach((PVOID*)&oCreateWindowExA, (PVOID)hkCreateWindowExA);
	DetourTransactionCommit();
}