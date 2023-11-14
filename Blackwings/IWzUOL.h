#pragma once

struct IWzUOL : IWzSerialize {
public:
    virtual HRESULT raw_Init(wchar_t* unk1, tagVARIANT unk2) = 0;
    virtual HRESULT get_UOL(wchar_t** unk1) = 0;
    virtual HRESULT put_UOL(wchar_t* unk1) = 0;
    virtual HRESULT get_filePath(wchar_t** unk1) = 0;
    virtual HRESULT get_className(wchar_t** unk1) = 0;
    virtual HRESULT get_localUOL(wchar_t** unk1) = 0;
    virtual HRESULT get_currentDirectory(wchar_t** unk1) = 0;
    virtual HRESULT put_currentDirectory(wchar_t* unk1) = 0;
};
