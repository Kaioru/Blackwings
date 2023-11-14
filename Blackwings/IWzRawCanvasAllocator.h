#pragma once

struct IWzRawCanvasAllocator : IUnknown {
public:
    virtual HRESULT raw_AllocCanvas(IWzCanvas* unk1, CANVAS_PIXFORMAT unk2, int unk3) = 0;
    virtual HRESULT raw_ConvertIfNotAvailable(IWzCanvas* unk1, int* unk2) = 0;
};
