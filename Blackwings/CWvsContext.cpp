#include "pch.h"

typedef CWvsContext* (__cdecl* _CWvsContext__GetInstance_t)();

_CWvsContext__GetInstance_t orig_CWvsContext__GetInstance = reinterpret_cast<_CWvsContext__GetInstance_t>(0x004298D0);

CWvsContext* CWvsContext::GetInstance()
{
    return orig_CWvsContext__GetInstance();
}
