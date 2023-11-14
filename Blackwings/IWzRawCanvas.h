#pragma once

class IWzRawCanvas : public IUnknown {
public:
    virtual HRESULT __stdcall get_pixelFormat(CANVAS_PIXFORMAT* unk1) = 0;
    virtual HRESULT __stdcall get_magLevel(int* unk1) = 0;
    virtual HRESULT __stdcall get_width(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall get_height(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall raw__LockAddress(int* unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT __stdcall raw__UnlockAddress(tagRECT* unk1) = 0;
    virtual HRESULT __stdcall raw_SetTexture(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall raw_GetTextureSize(tagRECT* unk1) = 0;
};
