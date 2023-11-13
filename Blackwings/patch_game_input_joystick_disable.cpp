#include "pch.h"

typedef VOID(__fastcall* _CWvsApp__InitializeInput_t)(
    void* pThis,
    void* edx
);

_CWvsApp__InitializeInput_t orig_CWvsApp__InitializeInput = reinterpret_cast<_CWvsApp__InitializeInput_t>(0x009C7E40);

VOID __fastcall hook_CWvsApp__InitializeInput(
    void* pThis,
    void* edx
)
{
    orig_CWvsApp__InitializeInput(pThis, edx);
    *(BOOL*)(CInputSystem::GetInstance() + 0x9E0) = FALSE;
}

VOID Patches::PatchGameInputJoystickDisable()
{
    DetourAttach((PVOID*)&orig_CWvsApp__InitializeInput, (PVOID)hook_CWvsApp__InitializeInput);
}
