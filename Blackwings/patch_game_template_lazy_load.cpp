#include "pch.h";

typedef VOID(__cdecl* _CMobTemplate__Load_t)();
typedef VOID(__cdecl* _CNpcTemplate__Load_t)();
typedef VOID(__cdecl* _CReactorTemplate__Load_t)();

_CMobTemplate__Load_t orig_CMobTemplate__Load = reinterpret_cast<_CMobTemplate__Load_t>(0x006611C0);
_CNpcTemplate__Load_t orig_CNpcTemplate__Load = reinterpret_cast<_CNpcTemplate__Load_t>(0x0067F190);
_CReactorTemplate__Load_t orig_CReactorTemplate__Load = reinterpret_cast<_CReactorTemplate__Load_t>(0x006d2ab0);

VOID __cdecl hook_CTemplate__Load() {}

VOID Patches::PatchGameTemplateLazyLoad()
{
    DetourAttach((PVOID*)&orig_CMobTemplate__Load, (PVOID)hook_CTemplate__Load);
    DetourAttach((PVOID*)&orig_CNpcTemplate__Load, (PVOID)hook_CTemplate__Load);
    DetourAttach((PVOID*)&orig_CReactorTemplate__Load, (PVOID)hook_CTemplate__Load);
}
