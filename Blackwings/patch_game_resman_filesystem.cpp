#include "pch.h"
#include "comip.h"
#include "comdef.h"

using T_get_rm = _com_ptr_t<_com_IIID<IWzResMan, &IID_IUnknown>>*(__cdecl*)();
using T_get_root = _com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>*(_cdecl*)();

template <typename T>
using T_PcCreateObject = VOID(__cdecl*)(const wchar_t *sUOL, T*, IUnknown *pUnkOuter);
using T_PcSetRootNameSpace = HRESULT(__cdecl*)(IUnknown* pNameSpace);

using T_IWzResMan__SetResManParam = HRESULT(_fastcall*)(IWzResMan* pThis, PVOID edx, RESMAN_PARAM nParam, int nRetainTime, int nNameSpaceCacheTime);
using T_IWzNameSpace__Mount = HRESULT(_fastcall*)(IWzNameSpace* pThis, PVOID edx, _bstr_t sPath, PVOID pDown, INT nPriority);
using T_IWzFileSystem__Init = HRESULT(_fastcall*)(IWzFileSystem* pThis, PVOID edx, _bstr_t sPath);
using T_CWvsApp__InitializeResMan = VOID(_fastcall*)(PVOID pThis, PVOID edx);
using T_CWvsApp__Dir_BackSlashToSlash = VOID(__cdecl*)(PCHAR sDir);
using T_CWvsApp__Dir_upDir = VOID(__cdecl*)(PCHAR sDir);

auto orig_get_rm = reinterpret_cast<T_get_rm>(0x00401D80);
auto orig_get_root = reinterpret_cast<T_get_root>(0x00590C90);
auto orig_PcCreateObject_ResMan = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzResMan, &IID_IUnknown>>>>(0x009C2EB0);
auto orig_PcCreateObject_NameSpace = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>>>(0x009C2F40);
auto orig_PcCreateObject_FileSystem = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzFileSystem, &IID_IUnknown>>>>(0x009C4710);
auto orig_PcSetRootNameSpace = reinterpret_cast<T_PcSetRootNameSpace>(0x009C0AE0);
auto orig_IWzResMan__SetResManParam = reinterpret_cast<T_IWzResMan__SetResManParam>(0x009C0920);
auto orig_IWzNameSpace__Mount = reinterpret_cast<T_IWzNameSpace__Mount>(0x009C8DB0);
auto orig_IWzFileSystem__Init = reinterpret_cast<T_IWzFileSystem__Init>(0x009C8E40);
auto orig_CWvsApp__InitializeResMan = reinterpret_cast<T_CWvsApp__InitializeResMan>(0x009C9540);
auto orig_CWvsApp__Dir_BackSlashToSlash = reinterpret_cast<T_CWvsApp__Dir_BackSlashToSlash>(0x009C1710);
auto orig_CWvsApp__Dir_upDir = reinterpret_cast<T_CWvsApp__Dir_upDir>(0x009C17F0);

VOID _fastcall hook_CWvsApp__InitializeResMan(void* pThis, void* edx) 
{
    auto pResMan = orig_get_rm();
    auto pNameSpace = orig_get_root();
    auto pFileSystem = new _com_ptr_t<_com_IIID<IWzFileSystem, &IID_IUnknown>>();

    orig_PcCreateObject_ResMan(L"ResMan", pResMan, NULL);
    orig_PcCreateObject_NameSpace(L"NameSpace", pNameSpace, NULL);
    orig_PcCreateObject_FileSystem(L"NameSpace#FileSystem", pFileSystem, NULL);

    orig_IWzResMan__SetResManParam(*pResMan, NULL, (RESMAN_PARAM)((INT)RC_AUTO_REPARSE | (INT)RC_AUTO_SERIALIZE), -1, -1);

    orig_PcSetRootNameSpace(*pNameSpace);

    char sStartPath[MAX_PATH];
    GetModuleFileNameA(NULL, sStartPath, MAX_PATH);
    orig_CWvsApp__Dir_BackSlashToSlash(sStartPath);
    orig_CWvsApp__Dir_upDir(sStartPath);

    SPDLOG_INFO("ResMan FileSystem hooked at path: {}", sStartPath);

    orig_IWzFileSystem__Init(*pFileSystem, NULL, _bstr_t(sStartPath));
    orig_IWzNameSpace__Mount(*pNameSpace, NULL, _bstr_t("/"), *pFileSystem, 0);

    auto pDataFileSystem = new _com_ptr_t<_com_IIID<IWzFileSystem, &IID_IUnknown>>();

    orig_PcCreateObject_FileSystem(L"NameSpace#FileSystem", pDataFileSystem, NULL);

    orig_IWzFileSystem__Init(*pDataFileSystem, NULL, _bstr_t("./Data"));
    orig_IWzNameSpace__Mount(*pNameSpace, NULL, _bstr_t("/"), *pDataFileSystem, 0);
}

VOID Patches::PatchGameResManFileSystem()
{
    DetourAttach((PVOID*)&orig_CWvsApp__InitializeResMan, (PVOID)hook_CWvsApp__InitializeResMan);
}
