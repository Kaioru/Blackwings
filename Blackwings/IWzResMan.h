#pragma once

enum RESMAN_PARAM : __int32
{
    RC_AUTO_SERIALIZE = 0x1,
    RC_AUTO_SERIALIZE_NO_CACHE = 0x2,
    RC_NO_AUTO_SERIALIZE = 0x4,
    RC_DEFAULT_AUTO_SERIALIZE = 0x0,
    RC_AUTO_SERIALIZE_MASK = 0x7,
    RC_AUTO_REPARSE = 0x10,
    RC_NO_AUTO_REPARSE = 0x20,
    RC_DEFAULT_AUTO_REPARSE = 0x0,
    RC_AUTO_REPARSE_MASK = 0x30,
};

struct IWzResMan : IUnknown {
public:
    virtual HRESULT get_rootNameSpace(IUnknown** unk1) = 0;
    virtual HRESULT put_rootNameSpace(IUnknown* unk1) = 0;
    virtual HRESULT raw_SetResManParam(RESMAN_PARAM unk1, int unk2, int unk3) = 0;
    virtual HRESULT raw_CreateObject(wchar_t* unk1, IUnknown** unk2) = 0;
    virtual HRESULT raw_GetObject(wchar_t* unk1, tagVARIANT unk2, tagVARIANT unk3, tagVARIANT* unk4) = 0;
    virtual HRESULT raw_SerializeObject(PVOID /* TODO IWzArchive */ unk1, tagVARIANT unk2, IUnknown** unk3) = 0;
    virtual HRESULT raw_FlushCachedObjects(int unk1) = 0;
    virtual HRESULT raw_OverrideObject(wchar_t* unk1, wchar_t* unk2) = 0;
};
