#pragma once

class IWzShape2D : public IWzSerialize {
public:
    virtual HRESULT __stdcall get_item(tagVARIANT unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT __stdcall get_count(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall get_x(int* unk1) = 0;
    virtual HRESULT __stdcall put_x(int unk1) = 0;
    virtual HRESULT __stdcall get_y(int* unk1) = 0;
    virtual HRESULT __stdcall put_y(int unk1) = 0;
    virtual HRESULT __stdcall get_x2(int* unk1) = 0;
    virtual HRESULT __stdcall put_x2(int unk1) = 0;
    virtual HRESULT __stdcall get_y2(int* unk1) = 0;
    virtual HRESULT __stdcall put_y2(int unk1) = 0;
    virtual HRESULT __stdcall raw_Move(int unk1, int unk2) = 0;
    virtual HRESULT __stdcall raw_Offset(int unk1, int unk2) = 0;
    virtual HRESULT __stdcall raw_Scale(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6) = 0;
    virtual HRESULT __stdcall raw_Insert(tagVARIANT unk1, tagVARIANT unk2) = 0;
    virtual HRESULT __stdcall raw_Remove(tagVARIANT unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall raw_Init(int unk1, int unk2) = 0;
};
