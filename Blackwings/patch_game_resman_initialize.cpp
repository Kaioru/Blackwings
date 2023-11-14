#include "pch.h"

using T_get_rm = _com_ptr_t<_com_IIID<IWzResMan, &IID_IUnknown>>*(__cdecl*)();
using T_get_root = _com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>*(_cdecl*)();
using T_get_sub = _com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>*(_cdecl*)(int nIdx);

template <typename T>
using T_PcCreateObject = VOID(__cdecl*)(const wchar_t *sUOL, T*, IUnknown *pUnkOuter);
using T_PcSetRootNameSpace = HRESULT(__cdecl*)(IUnknown* pNameSpace);

using T_IWzResMan__SetResManParam = HRESULT(_fastcall*)(IWzResMan* pThis, PVOID edx, RESMAN_PARAM nParam, int nRetainTime, int nNameSpaceCacheTime);
using T_IWzNameSpace__Mount = HRESULT(_fastcall*)(IWzNameSpace* pThis, PVOID edx, _bstr_t sPath, IWzNameSpace* pDown, INT nPriority);
using T_IWzNameSpace__Getitem = tagVARIANT*(__fastcall*)(IWzNameSpace* pThis, PVOID edx, tagVARIANT* result, _bstr_t sPath);
using T_IWzNameSpace__Get_NewEnum = _com_ptr_t<_com_IIID<IUnknown, &IID_IUnknown>>*(_fastcall*)(IWzNameSpace* pThis, PVOID edx, _com_ptr_t<_com_IIID<IUnknown, &IID_IUnknown>>* result);
using T_IWzFileSystem__Init = HRESULT(_fastcall*)(IWzFileSystem* pThis, PVOID edx, _bstr_t sPath);
using T_IWzPackage__Init = HRESULT(_fastcall*)(IWzPackage* pThis, PVOID edx, _bstr_t sKey, _bstr_t sBaseUOL, IWzSeekableArchive* pArchive);
using T_CWvsApp__InitializeResMan = VOID(_fastcall*)(PVOID pThis, PVOID edx);
using T_CWvsApp__Dir_BackSlashToSlash = VOID(__cdecl*)(PCHAR sDir);
using T_CWvsApp__Dir_upDir = VOID(__cdecl*)(PCHAR sDir);
using T_Ztl_variant_t__GetUnknown = IUnknown*(_fastcall*)(tagVARIANT* pThis, PVOID edx, bool fAddRef, bool fTryChangeType);

auto orig_get_rm = reinterpret_cast<T_get_rm>(0x00401D80);
auto orig_get_root = reinterpret_cast<T_get_root>(0x00590C90);
auto orig_get_sub = reinterpret_cast<T_get_sub>(0x009C1700);
auto orig_PcCreateObject_ResMan = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzResMan, &IID_IUnknown>>>>(0x009C2EB0);
auto orig_PcCreateObject_NameSpace = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>>>(0x009C2F40);
auto orig_PcCreateObject_FileSystem = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzFileSystem, &IID_IUnknown>>>>(0x009C4710);
auto orig_PcCreateObject_Package = reinterpret_cast<T_PcCreateObject<_com_ptr_t<_com_IIID<IWzPackage, &IID_IUnknown>>>>(0x009C47A0);
auto orig_PcSetRootNameSpace = reinterpret_cast<T_PcSetRootNameSpace>(0x009C0AE0);
auto orig_IWzResMan__SetResManParam = reinterpret_cast<T_IWzResMan__SetResManParam>(0x009C0920);
auto orig_IWzNameSpace__Mount = reinterpret_cast<T_IWzNameSpace__Mount>(0x009C8DB0);
auto orig_IWzNameSpace__Getitem = reinterpret_cast<T_IWzNameSpace__Getitem>(0x0059F940);
auto orig_IWzNameSpace__Get_NewEnum = reinterpret_cast<T_IWzNameSpace__Get_NewEnum>(0x00594C30);
auto orig_IWzFileSystem__Init = reinterpret_cast<T_IWzFileSystem__Init>(0x009C8E40);
auto orig_IWzPackage__Init = reinterpret_cast<T_IWzPackage__Init>(0x009C8EC0);
auto orig_CWvsApp__InitializeResMan = reinterpret_cast<T_CWvsApp__InitializeResMan>(0x009C9540);
auto orig_CWvsApp__Dir_BackSlashToSlash = reinterpret_cast<T_CWvsApp__Dir_BackSlashToSlash>(0x009C1710);
auto orig_CWvsApp__Dir_upDir = reinterpret_cast<T_CWvsApp__Dir_upDir>(0x009C17F0);
auto orig_Ztl_variant_t__GetUnknown = reinterpret_cast<T_Ztl_variant_t__GetUnknown>(0x00401A60);

BOOL bInitResMan = FALSE;

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

    orig_IWzFileSystem__Init(*pFileSystem, NULL, _bstr_t(sStartPath));
    SPDLOG_INFO("ResMan initialize hooked at path: {}", sStartPath);

    if (!bInitResMan && Config::GameResManUseFileSystem) {
        orig_IWzNameSpace__Mount(*pNameSpace, NULL, _bstr_t("/"), *pFileSystem, 0);

        auto pDataFileSystem = new _com_ptr_t<_com_IIID<IWzFileSystem, &IID_IUnknown>>();

        orig_PcCreateObject_FileSystem(L"NameSpace#FileSystem", pDataFileSystem, NULL);

        orig_IWzFileSystem__Init(*pDataFileSystem, NULL, _bstr_t("./Data"));
        orig_IWzNameSpace__Mount(*pNameSpace, NULL, _bstr_t("/"), *pDataFileSystem, 0);

        bInitResMan = TRUE;
    }

    if (!bInitResMan && Config::GameResManUsePackage) {
        auto pBasePackage = new _com_ptr_t<_com_IIID<IWzPackage, &IID_IUnknown>>();

        orig_PcCreateObject_Package(L"NameSpace#Package", pBasePackage, NULL);

        auto pBaseData = new tagVARIANT();
        orig_IWzNameSpace__Getitem(*pFileSystem, NULL, pBaseData, _bstr_t("Base.wz"));

        auto pBaseUnknown = orig_Ztl_variant_t__GetUnknown(pBaseData, NULL, FALSE, FALSE);
        auto pBaseArchive = new _com_ptr_t<_com_IIID<IWzSeekableArchive, &IID_IUnknown>>(pBaseUnknown);
        
        delete pBaseData;
        orig_IWzPackage__Init(*pBasePackage, NULL, _bstr_t("95"), _bstr_t("../Data"), *pBaseArchive);
        orig_IWzNameSpace__Mount(*pNameSpace, NULL, _bstr_t("/"), *pBasePackage, 0);

        auto pNewEnum = new _com_ptr_t<_com_IIID<IUnknown, &IID_IUnknown>>();
            
        orig_IWzNameSpace__Get_NewEnum(*pNameSpace, NULL, pNewEnum);

        std::vector<std::string> asCustomOrder;
        if (Config::GameResManHotfix)
            asCustomOrder.push_back(Config::GameTitle);

        for (auto i = 0; i < asCustomOrder.size(); i++) {
            auto pCustomPackage = new _com_ptr_t<_com_IIID<IWzPackage, &IID_IUnknown>>();

            orig_PcCreateObject_Package(L"NameSpace#Package", pCustomPackage, NULL);

            CString sFileName = CString(asCustomOrder[i].c_str());
            sFileName += ".wz";

            auto pCustomData = new tagVARIANT();
            orig_IWzNameSpace__Getitem(*pFileSystem, NULL, pCustomData, _bstr_t(sFileName));

            auto pCustomUnknown = orig_Ztl_variant_t__GetUnknown(pCustomData, NULL, FALSE, FALSE);
            auto pCustomArchive = new _com_ptr_t<_com_IIID<IWzSeekableArchive, &IID_IUnknown>>(pCustomUnknown);

            orig_IWzPackage__Init(*pCustomPackage, NULL, _bstr_t("95"), _bstr_t("/"), *pCustomArchive);
            orig_IWzNameSpace__Mount(*pNameSpace, NULL, _bstr_t("/"), *pCustomPackage, 0);
        }

        std::vector<std::string> asNameOrder;
        asNameOrder.push_back("Character");
        asNameOrder.push_back("Mob");
        asNameOrder.push_back("Skill");
        asNameOrder.push_back("Reactor");
        asNameOrder.push_back("Npc");
        asNameOrder.push_back("UI");
        asNameOrder.push_back("Quest");
        asNameOrder.push_back("Item");
        asNameOrder.push_back("Effect");
        asNameOrder.push_back("String");
        asNameOrder.push_back("Etc");
        asNameOrder.push_back("Morph");
        asNameOrder.push_back("TamingMob");
        asNameOrder.push_back("Sound");
        asNameOrder.push_back("Map");

        for (auto i = 0; i < asNameOrder.size(); i++) {
            auto pSubPackage = new _com_ptr_t<_com_IIID<IWzPackage, &IID_IUnknown>>();

            orig_PcCreateObject_Package(L"NameSpace#Package", pSubPackage, NULL);
            
            CString sFileName = CString(asNameOrder[i].c_str());
            sFileName += ".wz";

            auto pSubData = new tagVARIANT();
            orig_IWzNameSpace__Getitem(*pFileSystem, NULL, pSubData, _bstr_t(sFileName));

            auto pSubUnknown = orig_Ztl_variant_t__GetUnknown(pSubData, NULL, FALSE, FALSE);
            auto pSubArchive = new _com_ptr_t<_com_IIID<IWzSeekableArchive, &IID_IUnknown>>(pSubUnknown);

            auto pSubDirectory = new tagVARIANT();
            orig_IWzNameSpace__Getitem(*pNameSpace, NULL, pSubDirectory, _bstr_t(asNameOrder[i].c_str()));

            auto pSubDirectoryUnknown = orig_Ztl_variant_t__GetUnknown(pSubDirectory, NULL, FALSE, FALSE);
            auto pSubDirectoryArchive = (IWzSeekableArchive*)pSubDirectoryUnknown;

            auto pMainSub = orig_get_sub(i);

            ((_com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>*(_fastcall*)(
                _com_ptr_t<_com_IIID<IWzNameSpace, &IID_IUnknown>>*pThis,
                PVOID edx,
                IUnknown *p
            ))0x006CFE60)(
                pMainSub,
                NULL,
                pSubDirectoryArchive
            );

            orig_IWzPackage__Init(*pSubPackage, NULL, _bstr_t("95"), _bstr_t(asNameOrder[i].c_str()), *pSubArchive);

            auto pSub = new _com_ptr_t<_com_IIID<IWzPackage, &IID_IUnknown>>();

            orig_PcCreateObject_Package(L"NameSpace#Package", pSub, NULL);
            
            orig_IWzNameSpace__Mount(*pSub, NULL, _bstr_t("/"), *pSubPackage, 0);
            orig_IWzNameSpace__Mount(*orig_get_sub(i), NULL, _bstr_t("/"), *pSub, 0);
            SPDLOG_INFO("{}", asNameOrder[i]);
        }

        bInitResMan = TRUE;
    }
}

VOID Patches::PatchGameResManInitialize()
{
    DetourAttach((PVOID*)&orig_CWvsApp__InitializeResMan, (PVOID)hook_CWvsApp__InitializeResMan);
}
