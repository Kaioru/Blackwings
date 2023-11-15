#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <detours/detours.h>
#include <strsafe.h>
#include <iostream>
#include <stdio.h>

struct ExportContext
{
    BOOL    fHasOrdinal1;
    ULONG   nExports;
};

static BOOL CALLBACK ExportCallback(_In_opt_ PVOID pContext,
    _In_ ULONG nOrdinal,
    _In_opt_ LPCSTR pszSymbol,
    _In_opt_ PVOID pbTarget)
{
    (void)pContext;
    (void)pbTarget;
    (void)pszSymbol;

    ExportContext* pec = (ExportContext*)pContext;

    if (nOrdinal == 1) {
        pec->fHasOrdinal1 = TRUE;
    }
    pec->nExports++;

    return TRUE;
}

int main()
{
    LPCSTR rpszDllsRaw[256];
    LPCSTR rpszDllsOut[256];
    DWORD nDlls = 0;

    for (DWORD n = 0; n < ARRAYSIZE(rpszDllsRaw); n++) {
        rpszDllsRaw[n] = NULL;
        rpszDllsOut[n] = NULL;
    }

    rpszDllsRaw[nDlls++] = "Blackwings.dll";

    for (DWORD n = 0; n < nDlls; n++) {
        CHAR szDllPath[1024];
        PCHAR pszFilePart = NULL;

        if (!GetFullPathNameA(rpszDllsRaw[n], ARRAYSIZE(szDllPath), szDllPath, &pszFilePart)) {
            printf("Error: %s is not a valid path name..\n",
                rpszDllsRaw[n]);
            return 9002;
        }

        DWORD c = (DWORD)strlen(szDllPath) + 1;
        PCHAR psz = new CHAR[c];
        StringCchCopyA(psz, c, szDllPath);
        rpszDllsOut[n] = psz;

        HMODULE hDll = LoadLibraryExA(rpszDllsOut[n], NULL, DONT_RESOLVE_DLL_REFERENCES);
        if (hDll == NULL) {
            printf(" Error: %s failed to load (error %ld).\n",
                rpszDllsOut[n],
                GetLastError());
            return 9003;
        }

        ExportContext ec;
        ec.fHasOrdinal1 = FALSE;
        ec.nExports = 0;
        DetourEnumerateExports(hDll, &ec, ExportCallback);
        FreeLibrary(hDll);

        if (!ec.fHasOrdinal1) {
            printf("Error: %s does not export ordinal #1.\n", rpszDllsOut[n]);
            printf("See help entry DetourCreateProcessWithDllEx in Detours.chm.\n");
            return 9004;
        }

        STARTUPINFOA si;
        PROCESS_INFORMATION pi;
        CHAR szCommand[2048];
        CHAR szExe[1024];
        CHAR szFullExe[1024] = "\0";
        PCHAR pszFileExe = NULL;

        ZeroMemory(&si, sizeof(si));
        ZeroMemory(&pi, sizeof(pi));
        si.cb = sizeof(si);

        szCommand[0] = L'\0';

        StringCchCopyA(szExe, sizeof(szExe), "MapleStoryU.exe");

        DWORD dwFlags = CREATE_DEFAULT_ERROR_MODE | CREATE_SUSPENDED;

        SetLastError(0);
        SearchPathA(NULL, szExe, ".exe", ARRAYSIZE(szFullExe), szFullExe, &pszFileExe);

        if (!DetourCreateProcessWithDllsA(szFullExe[0] ? szFullExe : NULL, szCommand,
            NULL, NULL, TRUE, dwFlags, NULL, NULL,
            &si, &pi, nDlls, rpszDllsOut, NULL)) 
        {
            DWORD dwError = GetLastError();

            printf("DetourCreateProcessWithDllEx failed: %ld\n", dwError);

            if (dwError == ERROR_INVALID_HANDLE) {
#if DETOURS_64BIT
                printf("Can't detour a 32-bit target process from a 64-bit parent process.\n");
#else
                printf("Can't detour a 64-bit target process from a 32-bit parent process.\n");
#endif
            }

            ExitProcess(9009);
        }

        ResumeThread(pi.hThread);

        /*
        WaitForSingleObject(pi.hProcess, INFINITE);

        DWORD dwResult = 0;

        if (!GetExitCodeProcess(pi.hProcess, &dwResult)) {
            printf("GetExitCodeProcess failed: %ld\n", GetLastError());
            return 9010;
        }
        */

        for (DWORD n = 0; n < nDlls; n++) {
            if (rpszDllsOut[n] != NULL) {
                delete[] rpszDllsOut[n];
                rpszDllsOut[n] = NULL;
            }
        }

        return 0;
    }
}
