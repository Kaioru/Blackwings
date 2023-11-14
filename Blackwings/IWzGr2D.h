#pragma once

struct IWzGr2D : IUnknown {
public:
    virtual HRESULT raw_Initialize(unsigned int unk1, unsigned int unk2, tagVARIANT unk3, tagVARIANT unk4, tagVARIANT unk5) = 0;
    virtual HRESULT raw_Uninitialize() = 0;
    virtual HRESULT get_nextRenderTime(int* unk1) = 0;
    virtual HRESULT raw_UpdateCurrentTime(int unk1) = 0;
    virtual HRESULT raw_RenderFrame() = 0;
    virtual HRESULT raw_SetFrameSkip() = 0;
    virtual HRESULT raw_ToggleFpsPanel() = 0;
    virtual HRESULT raw_DisableFpsPanel() = 0;
    virtual HRESULT get_width(unsigned int* unk1) = 0;
    virtual HRESULT get_height(unsigned int* unk1) = 0;
    virtual HRESULT put_screenResolution(unsigned int unk1, unsigned int unk2) = 0;
    virtual HRESULT get_bpp(unsigned int* unk1) = 0;
    virtual HRESULT get_refreshRate(unsigned int* unk1) = 0;
    virtual HRESULT get_fps100(unsigned int* unk1) = 0;
    virtual HRESULT get_currentTime(int* unk1) = 0;
    virtual HRESULT get_fullScreen(int* unk1) = 0;
    virtual HRESULT put_fullScreen(int unk1) = 0;
    virtual HRESULT get_backColor(unsigned int* unk1) = 0;
    virtual HRESULT put_backColor(unsigned int unk1) = 0;
    virtual HRESULT get_redTone(IWzVector2D** unk1) = 0;
    virtual HRESULT get_greenBlueTone(IWzVector2D** unk1) = 0;
    virtual HRESULT get_center(IWzVector2D** unk1) = 0;
    virtual HRESULT raw_GetSnapshot(tagVARIANT unk1, unsigned int unk2, int unk3, int unk4) = 0;
    virtual HRESULT raw_CreateLayer(int unk1, int unk2, unsigned int unk3, unsigned int unk4, int unk5, tagVARIANT unk6, tagVARIANT unk7, IWzGr2DLayer** unk8) = 0;
    virtual HRESULT raw_AdjustCenter(int unk1, int unk2) = 0;
    virtual HRESULT raw_TakeScreenShot(wchar_t* unk1, int unk2) = 0;
    virtual HRESULT raw_SetVideoMode(int unk1) = 0;
    virtual HRESULT raw_SetVideoPath(wchar_t* unk1, int unk2, int unk3) = 0;
    virtual HRESULT raw_PlayVideo() = 0;
    virtual HRESULT raw_PauseVideo(int unk1) = 0;
    virtual HRESULT raw_StopVideo() = 0;
    virtual HRESULT get_videoStatus(int* unk1) = 0;
    virtual HRESULT put_videoVolume(int unk1) = 0;
};
