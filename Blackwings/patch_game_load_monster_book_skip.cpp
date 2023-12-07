#include "pch.h"

typedef BOOL(__fastcall* _CMonsterBookMan__LoadBook_t)(
    void* pThis,
    void* edx
);

_CMonsterBookMan__LoadBook_t orig_CMonsterBookMan__LoadBook = reinterpret_cast<_CMonsterBookMan__LoadBook_t>(0x00664C10);

BOOL __fastcall hook_CMonsterBookMan__LoadBook(
    void* pThis,
    void* edx
)
{
    return TRUE;
}

VOID Patches::PatchGameLoadMonsterBookSkip()
{
    DetourAttach((PVOID*)&orig_CMonsterBookMan__LoadBook, (PVOID)hook_CMonsterBookMan__LoadBook);
}
