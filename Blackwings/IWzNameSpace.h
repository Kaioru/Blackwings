#pragma once

class IWzNameSpaceProperty;
class IWzNameSpace : public IUnknown {
public:
    virtual HRESULT __stdcall get_item(wchar_t * unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall get_property(wchar_t* unk1, tagVARIANT unk2, IWzNameSpaceProperty** unk3) = 0;
    virtual HRESULT __stdcall get__NewEnum(IUnknown** unk1) = 0;
    virtual HRESULT __stdcall raw_Mount(wchar_t* unk1, IWzNameSpace* unk2, int unk3) = 0;
    virtual HRESULT __stdcall raw_Unmount(wchar_t* unk1, tagVARIANT unk2) = 0;
    virtual HRESULT __stdcall raw__OnMountEvent(IWzNameSpace* unk1, IWzNameSpace* unk2, wchar_t* unk3, int unk4) = 0;
    virtual HRESULT __stdcall raw__OnGetLocalObject(int unk1, wchar_t* unk2, int* unk3, tagVARIANT* unk4) = 0;
};
