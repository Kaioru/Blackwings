#include "pch.h"

typedef CInputSystem* (__cdecl* _CInputSystem__GetInstance_t)();

_CInputSystem__GetInstance_t orig_CInputSystem__GetInstance = reinterpret_cast<_CInputSystem__GetInstance_t>(0x0047D4B0);

CInputSystem* CInputSystem::GetInstance()
{
    return orig_CInputSystem__GetInstance();
}
