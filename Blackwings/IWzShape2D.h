#pragma once

struct IWzShape2D : IWzSerialize {
public:
    virtual HRESULT get_item(tagVARIANT unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT get_count(unsigned int* unk1) = 0;
    virtual HRESULT get_x(int* unk1) = 0;
    virtual HRESULT put_x(int unk1) = 0;
    virtual HRESULT get_y(int* unk1) = 0;
    virtual HRESULT put_y(int unk1) = 0;
    virtual HRESULT get_x2(int* unk1) = 0;
    virtual HRESULT put_x2(int unk1) = 0;
    virtual HRESULT get_y2(int* unk1) = 0;
    virtual HRESULT put_y2(int unk1) = 0;
    virtual HRESULT raw_Move(int unk1, int unk2) = 0;
    virtual HRESULT raw_Offset(int unk1, int unk2) = 0;
    virtual HRESULT raw_Scale(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6) = 0;
    virtual HRESULT raw_Insert(tagVARIANT unk1, tagVARIANT unk2) = 0;
    virtual HRESULT raw_Remove(tagVARIANT unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT raw_Init(int unk1, int unk2) = 0;
};
