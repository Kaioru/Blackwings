#pragma once

class IWzUOL : public IWzSerialize {
public:
    virtual HRESULT __stdcall raw_Init(wchar_t* unk1, tagVARIANT unk2) = 0;
    virtual HRESULT __stdcall get_UOL(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall put_UOL(wchar_t* unk1) = 0;
    virtual HRESULT __stdcall get_filePath(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall get_className(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall get_localUOL(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall get_currentDirectory(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall put_currentDirectory(wchar_t* unk1) = 0;
};
