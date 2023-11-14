#pragma once

class IWzNameSpaceWriter : public IUnknown {
public:
    virtual HRESULT __stdcall raw_CreateChildNameSpace(wchar_t* unk1, IWzNameSpaceWriter** unk2) = 0;
    virtual HRESULT __stdcall raw_AddObject(wchar_t* unk1, tagVARIANT unk2, tagVARIANT* unk3) = 0;
    virtual HRESULT __stdcall raw_Unlink(wchar_t* unk1) = 0;
};
