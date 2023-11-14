#pragma once

struct IWzProperty : IWzSerialize {
public:
    virtual HRESULT get_item(wchar_t* unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT put_item(wchar_t* unk1, tagVARIANT unk2) = 0;
    virtual HRESULT get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT get_count(unsigned int* unk1) = 0;
    virtual HRESULT raw_Add(wchar_t* unk1, tagVARIANT unk2, tagVARIANT unk3) = 0;
    virtual HRESULT raw_Remove(wchar_t* unk1) = 0;
    virtual HRESULT raw_Import(wchar_t* unk1) = 0;
};
