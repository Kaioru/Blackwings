#pragma once

struct IWzArchive : IUnknown {
public:
    virtual HRESULT get_loading(int* unk1) = 0;
    virtual HRESULT raw_Read(unsigned __int8* unk1, unsigned int unk2, unsigned int* unk3) = 0;
    virtual HRESULT raw_Write(unsigned __int8* unk1, unsigned int unk2, unsigned int* unk3) = 0;
    virtual HRESULT get_absoluteUOL(wchar_t** unk1) = 0;
    virtual HRESULT put_absoluteUOL(wchar_t* unk1) = 0;
    virtual HRESULT get_position(unsigned int* unk1) = 0;
    virtual HRESULT get_context(tagVARIANT* unk1) = 0;
    virtual HRESULT put_context(tagVARIANT unk1) = 0;
};
