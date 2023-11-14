#pragma once

class IWzNameSpaceProperty : public IUnknown {
public:
    virtual HRESULT __stdcall get_item(tagVARIANT unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall get_name(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall get_path(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall get_size(tagVARIANT* unk1) = 0;
    virtual HRESULT __stdcall get_checksum(int* unk1) = 0;
    virtual HRESULT __stdcall get_property(wchar_t* unk1, tagVARIANT* unk2) = 0;
};
