#pragma once

struct IWzNameSpaceProperty : IUnknown {
public:
    virtual HRESULT get_item(tagVARIANT unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT get_name(wchar_t** unk1) = 0;
    virtual HRESULT get_path(wchar_t** unk1) = 0;
    virtual HRESULT get_size(tagVARIANT* unk1) = 0;
    virtual HRESULT get_checksum(int* unk1) = 0;
    virtual HRESULT get_property(wchar_t* unk1, tagVARIANT* unk2) = 0;
};
