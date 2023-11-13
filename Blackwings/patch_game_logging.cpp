#include "pch.h"

#ifdef _DEBUG
#include <iostream>

typedef PVOID(_fastcall* _IWzResMan__GetObjectA_t)(
    PVOID pThis,
    PVOID edx,
    PVOID result,
    PVOID sUOL,
    const PVOID vParam,
    const PVOID vAux
    );

_IWzResMan__GetObjectA_t orig_IWzResMan__GetObjectA = reinterpret_cast<_IWzResMan__GetObjectA_t>(0x00404AA0);

PVOID _fastcall hook_IWzResMan__GetObjectA(
    PVOID pThis,
    PVOID edx,
    PVOID result,
    PVOID sUOL,
    const PVOID vParam,
    const PVOID vAux
)
{
    std::wcout << "IWzResMan::GetObjectA: " << *((wchar_t**)sUOL) << std::endl;
    return orig_IWzResMan__GetObjectA(pThis, edx, result, sUOL, vParam, vAux);
}

VOID Patches::PatchGameLogging()
{
    DetourAttach((PVOID*)&orig_IWzResMan__GetObjectA, (PVOID)hook_IWzResMan__GetObjectA);
}

#endif
