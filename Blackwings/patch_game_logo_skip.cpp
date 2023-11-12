#include "pch.h"

typedef VOID(__fastcall* _CLogo__Update_t)(
    void* pThis,
    void* edx
);

typedef VOID(__fastcall* _CLogo__LogoEnd_t)(
    void* pThis,
    void* edx
);

_CLogo__Update_t    orig_CLogo__Update  = reinterpret_cast<_CLogo__Update_t>(0x0060E430);
_CLogo__LogoEnd_t   orig_CLogo__LogoEnd = reinterpret_cast<_CLogo__LogoEnd_t>(0x0060BD00);

VOID __fastcall hook_CLogo__Update(
    void* pThis,
    void* edx
)
{
    orig_CLogo__LogoEnd(pThis, edx);
}

VOID Patches::PatchGameLogoSkip()
{
    DetourAttach((PVOID*)&orig_CLogo__Update, (PVOID)hook_CLogo__Update);
}
