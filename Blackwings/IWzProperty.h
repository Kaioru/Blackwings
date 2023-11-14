#pragma once

class IWzProperty : public IWzSerialize {
public:
    virtual HRESULT __stdcall get_item(wchar_t* unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall put_item(wchar_t* unk1, tagVARIANT unk2) = 0;
    virtual HRESULT __stdcall get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT __stdcall get_count(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall raw_Add(wchar_t* unk1, tagVARIANT unk2, tagVARIANT unk3) = 0;
    virtual HRESULT __stdcall raw_Remove(wchar_t* unk1) = 0;
    virtual HRESULT __stdcall raw_Import(wchar_t* unk1) = 0;
};
