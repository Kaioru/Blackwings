#pragma once

class IWzSeekableArchive : public IWzArchive {
public:
    virtual HRESULT __stdcall put_position(unsigned int unk1) = 0;
    virtual HRESULT __stdcall get_length(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall put_length(unsigned int unk1) = 0;
    virtual HRESULT __stdcall get_address(tagVARIANT* unk1) = 0;
    virtual HRESULT __stdcall raw_Rewind() = 0;
    virtual HRESULT __stdcall raw_ReadLock(wchar_t* unk1, unsigned int unk2, IWzSeekableArchive** unk3) = 0;
};
