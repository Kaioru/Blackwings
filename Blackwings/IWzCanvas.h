#pragma once

enum CANVAS_DITHERTYPE : __int32
{
    CD_NONE = 0x0,
    CD_FS0 = 0x1,
    CD_FS1 = 0x2,
    CD_FS = 0x3,
    CD_FD0 = 0x11,
    CD_FD1 = 0x12,
    CD_FD = 0x13,
};

enum CANVAS_LEVELMAP : __int32
{
    CL_ALL16 = 0x1,
    CL_ALL32 = 0x2,
    CL_ALL56 = 0x201,
    CL_USE32OVER1 = 0x10002,
    CL_USE32OVER2 = 0x20002,
    CL_USE56OVER1 = 0x10201,
    CL_USE56OVER2 = 0x20201,
};

enum CANVAS_PIXFORMAT : __int32
{
    CP_UNKNOWN = 0x0,
    CP_A4R4G4B4 = 0x1,
    CP_A8R8G8B8 = 0x2,
    CP_R5G6B5 = 0x201,
    CP_DXT3 = 0x402,
};

enum CANVAS_ALPHATYPE : unsigned __int32
{
    CA_OVERWRITE = 0xFFFFFFFF,
    CA_REMOVEALPHA = 0xFFFFFFFE,
};

class IWzRawCanvasAllocator;
class IWzRawCanvas;
class IWzProperty;
class IWzFont;
class IWzCanvas : public IWzSerialize {
public:
    virtual HRESULT __stdcall get_defaultDither(CANVAS_DITHERTYPE* unk1) = 0;
    virtual HRESULT __stdcall put_defaultDither(CANVAS_DITHERTYPE unk1) = 0;
    virtual HRESULT __stdcall get_defaultLevelMap(CANVAS_LEVELMAP* unk1) = 0;
    virtual HRESULT __stdcall put_defaultLevelMap(CANVAS_LEVELMAP unk1) = 0;
    virtual HRESULT __stdcall get_defaultAllocator(IWzRawCanvasAllocator** unk1) = 0;
    virtual HRESULT __stdcall put_defaultAllocator(IWzRawCanvasAllocator* unk1) = 0;
    virtual HRESULT __stdcall raw_Create(unsigned int unk1, unsigned int unk2, tagVARIANT unk3, tagVARIANT unk4) = 0;
    virtual HRESULT __stdcall raw_AddRawCanvas(int unk1, int unk2, IWzRawCanvas* unk3) = 0;
    virtual HRESULT __stdcall get_rawCanvas(int unk1, int unk2, IWzRawCanvas** unk3) = 0;
    virtual HRESULT __stdcall get_tileWidth(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall get_tileHeight(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall get_width(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall put_width(unsigned int unk1) = 0;
    virtual HRESULT __stdcall get_height(unsigned int* unk1) = 0;
    virtual HRESULT __stdcall put_height(unsigned int unk1) = 0;
    virtual HRESULT __stdcall get_pixelFormat(CANVAS_PIXFORMAT* unk1) = 0;
    virtual HRESULT __stdcall put_pixelFormat(CANVAS_PIXFORMAT unk1) = 0;
    virtual HRESULT __stdcall get_magLevel(int* unk1) = 0;
    virtual HRESULT __stdcall put_magLevel(int unk1) = 0;
    virtual HRESULT __stdcall raw_GetSnapshotU(unsigned int* unk1, unsigned int* unk2, unsigned int* unk3, unsigned int* unk4, CANVAS_PIXFORMAT* unk5, int* unk6) = 0;
    virtual HRESULT __stdcall raw_GetSnapshot(int* unk1, int* unk2, int* unk3, int* unk4, CANVAS_PIXFORMAT* unk5, int* unk6) = 0;
    virtual HRESULT __stdcall get_property(IWzProperty** unk1) = 0;
    virtual HRESULT __stdcall get_cx(int* unk1) = 0;
    virtual HRESULT __stdcall put_cx(int unk1) = 0;
    virtual HRESULT __stdcall get_cy(int* unk1) = 0;
    virtual HRESULT __stdcall put_cy(int unk1) = 0;
    virtual HRESULT __stdcall raw_SetClipRect(int unk1, int unk2, int unk3, int unk4, tagVARIANT unk5, tagVARIANT* unk6) = 0;
    virtual HRESULT __stdcall raw_Copy(int unk1, int unk2, IWzCanvas* unk3, tagVARIANT unk4) = 0;
    virtual HRESULT __stdcall raw_CopyEx(int unk1, int unk2, IWzCanvas* unk3, CANVAS_ALPHATYPE unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, tagVARIANT unk11) = 0;
    virtual HRESULT __stdcall get_pixel(int unk1, int unk2, unsigned int* unk3) = 0;
    virtual HRESULT __stdcall raw_DrawRectangle(int unk1, int unk2, unsigned int unk3, unsigned int unk4, unsigned int unk5) = 0;
    virtual HRESULT __stdcall raw_DrawLine(int unk1, int unk2, int unk3, int unk4, unsigned int unk5, tagVARIANT unk6) = 0;
    virtual HRESULT __stdcall raw_DrawPolygon() = 0;
    virtual HRESULT __stdcall raw_DrawText(int unk1, int unk2, wchar_t* unk3, IWzFont* unk4, tagVARIANT unk5, tagVARIANT unk6, unsigned int* unk7) = 0;
};
