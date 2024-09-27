#include "pch.h"

typedef decltype(&CreateMutexA)     LPCREATEMUTEXA;
typedef decltype(&CreateWindowExA)  LPCREATEWINDOWEXA;
typedef decltype(&RegCreateKeyExA)  LPREGCREATEKEYEXA;

LPCREATEMUTEXA      CreateMutexA_orig = (LPCREATEMUTEXA)Memory::AddressOf("KERNEL32", "CreateMutexA");
LPCREATEMUTEXA      CreateMutexA_hook = [](
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL                  bInitialOwner,
    LPCSTR                lpName
    ) -> HANDLE
    {
        OutputDebugStringA(lpName);
        return CreateMutexA_orig(lpMutexAttributes, bInitialOwner, lpName);
    };

LPCREATEWINDOWEXA   CreateWindowExA_orig = (LPCREATEWINDOWEXA)Memory::AddressOf("USER32", "CreateWindowExA");
LPCREATEWINDOWEXA   CreateWindowExA_hook = [](
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
    ) -> HWND {
        OutputDebugStringA(lpClassName);
        return CreateWindowExA_orig(
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
    };

LPREGCREATEKEYEXA   RegCreateKeyA_orig = (LPREGCREATEKEYEXA)Memory::AddressOf("ADVAPI32", "RegCreateKeyExA");
LPREGCREATEKEYEXA   RegCreateKeyA_hook = [](
    HKEY hKey,
    LPCSTR lpSubKey,
    DWORD Reserved,
    LPSTR lpClass,
    DWORD dwOptions,
    REGSAM samDesired,
    const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    PHKEY phkResult,
    LPDWORD lpdwDisposition
    ) -> LSTATUS {
        OutputDebugStringA("IM HERE");
        return RegCreateKeyA_orig(HKEY_CURRENT_USER, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition);
    };

VOID Patches::PatchWinAPI()
{
    Memory::Trampoline((PVOID*)&CreateMutexA_orig, (PVOID)CreateMutexA_hook);
    Memory::Trampoline((PVOID*)&CreateWindowExA_orig, (PVOID)CreateWindowExA_hook);
    //Memory::Trampoline((PVOID*)&RegCreateKeyA_orig, (PVOID)RegCreateKeyA_hook);

    OutputDebugStringA("Patched");
}