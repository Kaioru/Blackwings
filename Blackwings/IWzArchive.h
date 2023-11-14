#pragma once

class IWzArchive : public IUnknown {
public:
    virtual HRESULT __stdcall get_loading(int* unk1) = 0;
    virtual HRESULT __stdcall raw_Read(unsigned __int8* unk1, unsigned int unk2, unsigned int* unk3) = 0;
    virtual HRESULT __stdcall raw_Write(unsigned __int8* unk1, unsigned int unk2, unsigned int* unk3) = 0;
    virtual HRESULT __stdcall get_absoluteUOL(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall put_absoluteUOL(wchar_t* unk1) = 0;
    virtual HRESULT __stdcall get_position(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall get_context(tagVARIANT* unk1) = 0;
    virtual HRESULT __stdcall put_context(tagVARIANT unk1) = 0;
};
