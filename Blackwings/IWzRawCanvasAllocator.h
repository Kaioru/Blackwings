#pragma once

class IWzRawCanvasAllocator : public IUnknown {
public:
    virtual HRESULT __stdcall raw_AllocCanvas(IWzCanvas* unk1, CANVAS_PIXFORMAT unk2, int unk3) = 0;
    virtual HRESULT __stdcall raw_ConvertIfNotAvailable(IWzCanvas* unk1, int* unk2) = 0;
};
