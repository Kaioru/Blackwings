#pragma once

enum LAYER_BLENDTYPE : __int32
{
    LB_NORMAL = 0x0,
    LB_ADD = 0x1,
    LB_INVERSE = 0x2,
    LB_ISOLATED = 0x4,
};

enum GR2D_ANITYPE : __int32
{
    GA_STOP = 0x0,
    GA_WAIT = 0x100,
    GA_NORMAL = 0x0,
    GA_FIRST = 0x10,
    GA_REPEAT = 0x20,
};

struct IWzCanvas;
struct IWzGr2DLayer : IWzVector2D {
public:
    virtual HRESULT get_z(int* unk1) = 0;
    virtual HRESULT put_z(int unk1) = 0;
    virtual HRESULT get_width(int* unk1) = 0;
    virtual HRESULT put_width(int unk1) = 0;
    virtual HRESULT get_height(int* unk1) = 0;
    virtual HRESULT put_height(int unk1) = 0;
    virtual HRESULT get_lt(IWzVector2D** unk1) = 0;
    virtual HRESULT get_rb(IWzVector2D** unk1) = 0;
    virtual HRESULT raw_InterlockedOffset(int unk1, int unk2, int unk3, int unk4) = 0;
    virtual HRESULT get_flip(int* unk1) = 0;
    virtual HRESULT put_flip(int unk1) = 0;
    virtual HRESULT get_color(unsigned int* unk1) = 0;
    virtual HRESULT put_color(unsigned int unk1) = 0;
    virtual HRESULT get_alpha(IWzVector2D** unk1) = 0;
    virtual HRESULT get_redTone(IWzVector2D** unk1) = 0;
    virtual HRESULT get_greenBlueTone(IWzVector2D** unk1) = 0;
    virtual HRESULT get_blend(LAYER_BLENDTYPE* unk1) = 0;
    virtual HRESULT put_blend(LAYER_BLENDTYPE unk1) = 0;
    virtual HRESULT get_overlay(tagVARIANT* unk1) = 0;
    virtual HRESULT put_overlay(tagVARIANT unk1) = 0;
    virtual HRESULT get_canvas(tagVARIANT unk1, IWzCanvas** unk2) = 0;
    virtual HRESULT raw_InsertCanvas(IWzCanvas* unk1, tagVARIANT unk2, tagVARIANT unk3, tagVARIANT unk4, tagVARIANT unk5, tagVARIANT unk6, tagVARIANT unk7) = 0;
    virtual HRESULT raw_RemoveCanvas(tagVARIANT unk1, IWzCanvas** unk2) = 0;
    virtual HRESULT raw_ShiftCanvas(tagVARIANT unk1) = 0;
    virtual HRESULT raw_Animate(GR2D_ANITYPE unk1, tagVARIANT unk2, tagVARIANT unk3) = 0;
    virtual HRESULT get_animationState(int* unk1) = 0;
    virtual HRESULT get_visible(int* unk1) = 0;
    virtual HRESULT put_visible(int unk1) = 0;
};
