#pragma once

struct IWzList : IWzSerialize {
public:
    virtual HRESULT get_item(unsigned int unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT put_item(unsigned int unk1, tagVARIANT unk2) = 0;
    virtual HRESULT get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT get_count(unsigned int* unk1) = 0;
    virtual HRESULT raw_Insert(tagVARIANT unk1, tagVARIANT unk2) = 0;
    virtual HRESULT raw_Remove(int unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT raw_Array(unsigned int unk1) = 0;
    virtual HRESULT raw_List() = 0;
};
