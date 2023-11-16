#include "pch.h"

struct _bstr_t_2 {
    struct {
        wchar_t* m_wstr;
        char* m_str;
        unsigned int m_RefCount;
    }*m_Data;
};
struct Ztl_variant_t : _variant_t {};
struct Ztl_bstr_t : _bstr_t_2 {};

using T_IWzResMan__GetObjectA = PVOID(_fastcall*)(
    IWzResMan* pThis, PVOID edx,
    Ztl_variant_t* result,
    Ztl_bstr_t sUOL,
    const Ztl_variant_t* vParam,
    const Ztl_variant_t* vAux
);

typedef VOID(_fastcall* _Ztl_bstr_t__constuctorA_t)(Ztl_bstr_t* pThis, PVOID edx, const char* s);
typedef VOID(_fastcall* _Ztl_bstr_t__constuctorW_t)(Ztl_bstr_t* pThis, PVOID edx, const wchar_t* s);
typedef LONG(_fastcall* _bstr_t__Data_t__Release_t)(PVOID pThis, PVOID edx);

_Ztl_bstr_t__constuctorA_t orig_Ztl_bstr_t__constuctorA = reinterpret_cast<_Ztl_bstr_t__constuctorA_t>(0x00404890);
_Ztl_bstr_t__constuctorW_t orig_Ztl_bstr_t__constuctorW = reinterpret_cast<_Ztl_bstr_t__constuctorW_t>(0x004048B0);
_bstr_t__Data_t__Release_t orig_bstr_t__Data_t__Release = reinterpret_cast<_bstr_t__Data_t__Release_t>(0x00403AE0);

auto orig_IWzResMan__GetObjectA = reinterpret_cast<T_IWzResMan__GetObjectA>(0x00404AA0);

PVOID _fastcall hook_IWzResMan__GetObjectA(
    IWzResMan* pThis, PVOID edx,
    Ztl_variant_t* result,
    Ztl_bstr_t sUOL,
    const Ztl_variant_t* vParam,
    const Ztl_variant_t* vAux
)
{
    CStringW sPath(Config::GameResManUseFileSystem ? Config::GameTitle : "");
    sPath += "/Overrides.img/";
    sPath += sUOL.m_Data->m_wstr;

    Ztl_bstr_t sHotfix;
    orig_Ztl_bstr_t__constuctorW(&sHotfix, NULL, sPath.GetString());

    HRESULT hResult = pThis->raw_GetObject(
        sHotfix.m_Data->m_wstr,
        *vParam,
        *vAux,
        result
    );

#ifdef _DEBUG
    std::wcout << "IWzResMan::GetObjectA " << sUOL.m_Data->m_wstr << std::endl;
#endif

    if (sHotfix.m_Data)
        orig_bstr_t__Data_t__Release(sHotfix.m_Data, NULL);

    if (hResult == S_OK) {
        if (sUOL.m_Data)
            orig_bstr_t__Data_t__Release(sUOL.m_Data, NULL);
        return result;
    }
    return orig_IWzResMan__GetObjectA(pThis, edx, result, sUOL, vParam, vAux);
}

VOID Patches::PatchGameResManCustomOverrides()
{
    DetourAttach((PVOID*)&orig_IWzResMan__GetObjectA, (PVOID)hook_IWzResMan__GetObjectA);
}
