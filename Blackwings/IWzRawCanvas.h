#pragma once

struct IWzRawCanvas : IUnknown {
public:
    virtual HRESULT get_pixelFormat(CANVAS_PIXFORMAT* unk1) = 0;
    virtual HRESULT get_magLevel(int* unk1) = 0;
    virtual HRESULT get_width(unsigned int* unk1) = 0;
    virtual HRESULT get_height(unsigned int* unk1) = 0;
    virtual HRESULT raw__LockAddress(int* unk1, tagVARIANT* unk2) = 0;
    virtual HRESULT raw__UnlockAddress(tagRECT* unk1) = 0;
    virtual HRESULT raw_SetTexture(unsigned int* unk1) = 0;
    virtual HRESULT raw_GetTextureSize(tagRECT* unk1) = 0;
};
