// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#define LIB_INJECT_NAME "Blackwings.dll"

INT WINAPI WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance,
    PSTR pCmdLine, 
    int nCmdShow
) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));

    if (!DetourCreateProcessWithDllExA(
        "MapleStory.exe", 
        NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi, LIB_INJECT_NAME, NULL
    )) {
        OutputDebugStringA("ERROR1");
        return 1;
    }

    ResumeThread(pi.hThread);
    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD dwExitCode;

    if (!GetExitCodeProcess(pi.hProcess, &dwExitCode)) {
        OutputDebugStringA("ERROR2");
        return 1;
    }

    return dwExitCode;
}