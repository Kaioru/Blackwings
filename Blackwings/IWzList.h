#pragma once

class IWzList : public IWzSerialize {
public:
    virtual HRESULT __stdcall get_item(unsigned int unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall put_item(unsigned int unk1, tagVARIANT unk2) = 0;
    virtual HRESULT __stdcall get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT __stdcall get_count(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall raw_Insert(tagVARIANT unk1, tagVARIANT unk2) = 0;
    virtual HRESULT __stdcall raw_Remove(int unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall raw_Array(unsigned int unk1) = 0;
    virtual HRESULT __stdcall raw_List() = 0;
};
