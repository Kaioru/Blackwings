#include "pch.h"

const INT RC_AUTO_SERIALIZE = 0x1;
const INT RC_AUTO_SERIALIZE_NO_CACHE = 0x2;
const INT RC_NO_AUTO_SERIALIZE = 0x4;
const INT RC_DEFAULT_AUTO_SERIALIZE = 0x0;
const INT RC_AUTO_SERIALIZE_MASK = 0x7;
const INT RC_AUTO_REPARSE = 0x10;
const INT RC_NO_AUTO_REPARSE = 0x20;
const INT RC_DEFAULT_AUTO_REPARSE = 0x0;
const INT RC_AUTO_REPARSE_MASK = 0x30;

typedef PVOID(__cdecl* _get_rm_t)();
typedef PVOID(__cdecl* _get_root_t)();
typedef VOID(__fastcall* _Ztl_bstr_t_constructor_t)(PVOID pThis, PVOID edx, const char* s);

typedef PVOID(_fastcall* _IWzResMan__operator_deref_t)(PVOID pThis, PVOID edx);
typedef HRESULT(_fastcall* _IWzResMan__SetResManParam_t)(
    PVOID pThis, PVOID edx,
    int nParam,
    int nRetainTime,
    int nNameSpaceCacheTime
);

typedef PVOID(_fastcall* _IWzNameSpace__operator_deref_t)(PVOID pThis, PVOID edx);
typedef HRESULT(_fastcall* _IWzNameSpace__Mount_t)(PVOID pThis, PVOID edx, PVOID sPath, PVOID pDown, INT nPriority);
typedef PVOID(_fastcall* _IWzFileSystem__constructor_t)(PVOID pThis, PVOID edx);
typedef PVOID(_fastcall* _IWzFileSystem__operator_deref_t)(PVOID pThis, PVOID edx);
typedef HRESULT(_fastcall* _IWzFileSystem__Init_t)(PVOID pThis, PVOID edx, PVOID sPath);
typedef PVOID(_fastcall* _IWzPackage__operator_deref_t)(PVOID pThis, PVOID edx);
typedef HRESULT(__cdecl* _PcSetRootNameSpace_t)(PVOID pNamespace);
typedef VOID(__cdecl* _PcCreateObject_IWzResMan_t)(const wchar_t* sUOL, PVOID pObj, PVOID* pUnkOuter);
typedef VOID(__cdecl* _PcCreateObject_IWzNameSpace_t)(const wchar_t* sUOL, PVOID pObj, PVOID* pUnkOuter);
typedef VOID(__cdecl* _PcCreateObject_IWzFileSystem_t)(const wchar_t* sUOL, PVOID pObj, PVOID* pUnkOuter);

typedef VOID(__cdecl* _CWvsApp__Dir_BackSlashToSlash_t)(PCHAR sDir);
typedef VOID(__cdecl* _CWvsApp__Dir_upDir_t)(PCHAR sDir);
typedef VOID(_fastcall* _CWvsApp__InitializeResMan_t)(PVOID pThis, PVOID edx);

_get_rm_t orig_get_rm = reinterpret_cast<_get_rm_t>(0x00401D80);
_get_root_t orig_get_root = reinterpret_cast<_get_rm_t>(0x00590C90);
_Ztl_bstr_t_constructor_t orig_Ztl_bstr_t_constructor = reinterpret_cast<_Ztl_bstr_t_constructor_t>(0x00404890);

_IWzResMan__operator_deref_t orig_IWzResMan__deref = reinterpret_cast<_IWzResMan__operator_deref_t>(0x00401DE0);
_IWzResMan__SetResManParam_t orig_IWzResMan__SetResManParam = reinterpret_cast<_IWzResMan__SetResManParam_t>(0x009C0920);
_IWzNameSpace__operator_deref_t orig_IWzNameSpace__operator_deref = reinterpret_cast<_IWzNameSpace__operator_deref_t>(0x009C19A0);
_IWzNameSpace__Mount_t orig_IWzNameSpace__Mount = reinterpret_cast<_IWzNameSpace__Mount_t>(0x009C8DB0);
_IWzFileSystem__constructor_t orig_IWzFileSystem__constructor = reinterpret_cast<_IWzNameSpace__operator_deref_t>(0x009C1A50);
_IWzFileSystem__operator_deref_t orig_IWzFileSystem__operator_deref = reinterpret_cast<_IWzFileSystem__operator_deref_t>(0x009C1A60);
_IWzFileSystem__Init_t orig_IWzFileSystem__Init = reinterpret_cast<_IWzFileSystem__Init_t>(0x009C8E40);
_IWzPackage__operator_deref_t orig__IWzPackage__operator_deref = reinterpret_cast<_IWzPackage__operator_deref_t>(0x009C1AA0);
_PcSetRootNameSpace_t orig_PcSetRootNameSpace = reinterpret_cast<_PcSetRootNameSpace_t>(0x009C0AE0);
_PcCreateObject_IWzResMan_t orig_PcCreateObject_IWzResMan = reinterpret_cast<_PcCreateObject_IWzResMan_t>(0x009C2EB0);
_PcCreateObject_IWzNameSpace_t orig_PcCreateObject_IWzNameSpace = reinterpret_cast<_PcCreateObject_IWzResMan_t>(0x009C2F40);
_PcCreateObject_IWzFileSystem_t orig_PcCreateObject_IWzFileSystem = reinterpret_cast<_PcCreateObject_IWzFileSystem_t>(0x009C4710);

_CWvsApp__Dir_BackSlashToSlash_t orig_CWvsApp__Dir_BackSlashToSlash = reinterpret_cast<_CWvsApp__Dir_BackSlashToSlash_t>(0x009C1710);
_CWvsApp__Dir_upDir_t orig_CWvsApp__Dir_upDir = reinterpret_cast<_CWvsApp__Dir_upDir_t>(0x009C17F0);
_CWvsApp__InitializeResMan_t orig_CWvsApp__InitializeResMan = reinterpret_cast<_CWvsApp__InitializeResMan_t>(0x009C9540);

VOID _fastcall hook_CWvsApp__InitializeResMan(void* pThis, void* edx) 
{
    auto pResman = orig_get_rm();
    orig_PcCreateObject_IWzResMan(L"ResMan", pResman, NULL);

    auto pInstance = orig_IWzResMan__deref(pResman, NULL);
    orig_IWzResMan__SetResManParam(pInstance, NULL, RC_AUTO_REPARSE | RC_AUTO_SERIALIZE, -1, -1);

    auto pRoot = orig_get_root();
    orig_PcCreateObject_IWzNameSpace(L"NameSpace", pRoot, NULL);

    auto pNamespace = orig_IWzNameSpace__operator_deref(pRoot, NULL);
    orig_PcSetRootNameSpace(pNamespace);

    auto pFileSystem = 0;
    orig_IWzFileSystem__constructor(&pFileSystem, NULL);
    orig_PcCreateObject_IWzFileSystem(L"NameSpace#FileSystem", &pFileSystem, NULL);

    char sStartPath[MAX_PATH];
    GetModuleFileNameA(NULL, sStartPath, MAX_PATH);
    orig_CWvsApp__Dir_BackSlashToSlash(sStartPath);
    orig_CWvsApp__Dir_upDir(sStartPath);

    SPDLOG_INFO("ResMan FileSystem hooked at path: {}", sStartPath);
    
    PVOID sPath;
    PVOID pDown;

    auto pGameFileSystem = orig_IWzFileSystem__operator_deref(&pFileSystem, NULL);
    orig_Ztl_bstr_t_constructor(&sPath, NULL, sStartPath);
    orig_IWzFileSystem__Init(pGameFileSystem, NULL, sPath);

    auto pGameNameSpace = orig_IWzNameSpace__operator_deref(pRoot, NULL);
    pDown = orig__IWzPackage__operator_deref(&pFileSystem, NULL);
    orig_Ztl_bstr_t_constructor(&sPath, NULL, "/");
    orig_IWzNameSpace__Mount(pGameNameSpace, NULL, sPath, pDown, 0);

    int pDataFileSystem = 0;
    orig_IWzFileSystem__constructor(&pDataFileSystem, NULL);
    orig_PcCreateObject_IWzFileSystem(L"NameSpace#FileSystem", &pDataFileSystem, NULL);
    orig_Ztl_bstr_t_constructor(&sPath, NULL, "./Data");
    orig_IWzFileSystem__Init(
        orig_IWzFileSystem__operator_deref(&pDataFileSystem, NULL),
        NULL, 
        sPath
    );
    
    auto pDataNameSpace = orig_IWzNameSpace__operator_deref(pRoot, NULL);
    pDown = orig__IWzPackage__operator_deref(&pDataFileSystem, NULL);
    orig_Ztl_bstr_t_constructor(&sPath, NULL, "/");
    orig_IWzNameSpace__Mount(pDataNameSpace, NULL, sPath, pDown, 0);
}

VOID Patches::PatchGameResManFileSystem()
{
    DetourAttach((PVOID*)&orig_CWvsApp__InitializeResMan, (PVOID)hook_CWvsApp__InitializeResMan);
}
