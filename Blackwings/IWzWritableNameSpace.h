#pragma once

struct IWzWritableNameSpace : IWzNameSpace {
public:
    virtual HRESULT raw_CreateChildNameSpace(wchar_t* unk1, IWzNameSpace** unk2) = 0;
    virtual HRESULT raw_AddObject(wchar_t* unk1, tagVARIANT unk2, tagVARIANT* unk3) = 0;
    virtual HRESULT raw_Unlink(wchar_t* unk1) = 0;
};
