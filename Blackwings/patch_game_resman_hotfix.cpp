#include "pch.h"
#include <fmt/xchar.h>

struct _variant_t : tagVARIANT {};
struct Ztl_variant_t : _variant_t {};

struct _bstr_t {
    struct {
        wchar_t* m_wstr;
        char* m_str;
        unsigned int m_RefCount;
    }* m_Data;
};
struct Ztl_bstr_t : _bstr_t {};

typedef VOID(_fastcall* _Ztl_bstr_t__constuctorA_t)(Ztl_bstr_t* pThis, PVOID edx, const char* s);
typedef VOID(_fastcall* _Ztl_bstr_t__constuctorW_t)(Ztl_bstr_t* pThis, PVOID edx, const wchar_t* s);
typedef LONG(_fastcall* _bstr_t__Data_t__Release_t)(PVOID pThis, PVOID edx);
typedef PVOID(_fastcall* _IWzResMan__GetObjectA_t)(
    PVOID pThis,
    PVOID edx,
    Ztl_variant_t* result,
    Ztl_bstr_t sUOL,
    const Ztl_variant_t* vParam,
    const Ztl_variant_t* vAux
);
typedef HRESULT(__stdcall* _IWzResMan__raw_GetObject_t)(
    PVOID pThis,
    wchar_t* sUOL,
    DWORD vParam,
    unsigned int vParamHi32,
    unsigned int vParamLo32,
    unsigned int vParamMid32,
    DWORD vAux,
    unsigned int vAuxHi32,
    unsigned int vAuxLo32,
    unsigned int vAuxMid32,
    tagVARIANT* result
);
typedef HRESULT(__stdcall* _IWzResMan__raw_OverrideObject_t)
(
    PVOID pThis,
    wchar_t* sUOL,
    wchar_t* sOverride
);

_Ztl_bstr_t__constuctorA_t orig_Ztl_bstr_t__constuctorA = reinterpret_cast<_Ztl_bstr_t__constuctorA_t>(0x00404890);
_Ztl_bstr_t__constuctorW_t orig_Ztl_bstr_t__constuctorW = reinterpret_cast<_Ztl_bstr_t__constuctorW_t>(0x004048B0);
_bstr_t__Data_t__Release_t orig_bstr_t__Data_t__Release = reinterpret_cast<_bstr_t__Data_t__Release_t>(0x00403AE0);
_IWzResMan__GetObjectA_t orig_IWzResMan__GetObjectA = reinterpret_cast<_IWzResMan__GetObjectA_t>(0x00404AA0);

PVOID _fastcall hook_IWzResMan__GetObjectA(
    PVOID pThis,
    PVOID edx,
    Ztl_variant_t* result,
    Ztl_bstr_t sUOL,
    const Ztl_variant_t* vParam,
    const Ztl_variant_t* vAux
)
{
    VOID** pTable = *reinterpret_cast<void***>(pThis);
    _IWzResMan__raw_GetObject_t orig_raw_GetObject = (_IWzResMan__raw_GetObject_t)pTable[7];
    Ztl_bstr_t sFile;
    Ztl_bstr_t sHotfix;

    orig_Ztl_bstr_t__constuctorA(&sFile, NULL, Config::GameTitle);
    orig_Ztl_bstr_t__constuctorW(&sHotfix, NULL, fmt::format(L"{}/Hotfix.img/{}", sFile.m_Data->m_wstr, sUOL.m_Data->m_wstr).c_str());

    HRESULT hResult = orig_raw_GetObject(
        pThis,
        sHotfix.m_Data->m_wstr,
        *(DWORD*)&vParam->vt,
        vParam->decVal.Hi32,
        vParam->decVal.Lo32,
        vParam->decVal.Mid32,
        *(DWORD*)&vAux->vt,
        vAux->decVal.Hi32,
        vAux->decVal.Lo32,
        vAux->decVal.Mid32,
        result
    );

#ifdef _DEBUG
    std::wcout << "IWzResMan::GetObjectA " << sUOL.m_Data->m_wstr << std::endl;
#endif

    if (sFile.m_Data)
        orig_bstr_t__Data_t__Release(sFile.m_Data, NULL);

    if (sHotfix.m_Data)
        orig_bstr_t__Data_t__Release(sHotfix.m_Data, NULL);

    if (hResult == S_OK) {
        if (sUOL.m_Data)
            orig_bstr_t__Data_t__Release(sUOL.m_Data, NULL);
        return result;
    }

    return orig_IWzResMan__GetObjectA(pThis, edx, result, sUOL, vParam, vAux);
}

VOID Patches::PatchGameResManHotfix()
{
    DetourAttach((PVOID*)&orig_IWzResMan__GetObjectA, (PVOID)hook_IWzResMan__GetObjectA);
}
