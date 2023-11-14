#pragma once

struct IWzSeekableArchive : IWzArchive {
public:
    virtual HRESULT put_position(unsigned int unk1) = 0;
    virtual HRESULT get_length(unsigned int* unk1) = 0;
    virtual HRESULT put_length(unsigned int unk1) = 0;
    virtual HRESULT get_address(tagVARIANT* unk1) = 0;
    virtual HRESULT raw_Rewind() = 0;
    virtual HRESULT raw_ReadLock(wchar_t* unk1, unsigned int unk2, IWzSeekableArchive** unk3) = 0;
};
