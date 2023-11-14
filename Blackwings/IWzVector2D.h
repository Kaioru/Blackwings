#pragma once

struct IWzVector2D : IWzShape2D {
public:
    virtual HRESULT get_currentTime(int* unk1) = 0;
    virtual HRESULT put_currentTime(int unk1) = 0;
    virtual HRESULT get_origin(tagVARIANT* unk1) = 0;
    virtual HRESULT put_origin(tagVARIANT unk1) = 0;
    virtual HRESULT get_rx(int* unk1) = 0;
    virtual HRESULT put_rx(int unk1) = 0;
    virtual HRESULT get_ry(int* unk1) = 0;
    virtual HRESULT put_ry(int unk1) = 0;
    virtual HRESULT get_a(long double* unk1) = 0;
    virtual HRESULT get_ra(long double* unk1) = 0;
    virtual HRESULT put_ra(long double unk1) = 0;
    virtual HRESULT get_flipX(int* unk1) = 0;
    virtual HRESULT put_flipX(int unk1) = 0;
    virtual HRESULT raw__GetSnapshot(int* unk1, int* unk2, int* unk3, int* unk4, int* unk5, int* unk6, long double* unk7, long double* unk8, tagVARIANT unk9) = 0;
    virtual HRESULT raw_RelMove(int unk1, int unk2, tagVARIANT unk3, tagVARIANT unk4) = 0;
    virtual HRESULT raw_RelOffset(int unk1, int unk2, tagVARIANT unk3, tagVARIANT unk4) = 0;
    virtual HRESULT raw_Ratio(IWzVector2D* unk1, int unk2, int unk3, int unk4, int unk5) = 0;
    virtual HRESULT raw_WrapClip(tagVARIANT unk1, int unk2, int unk3, unsigned int unk4, unsigned int unk5, tagVARIANT unk6) = 0;
    virtual HRESULT raw_Rotate(long double unk1, tagVARIANT unk2) = 0;
    virtual HRESULT get_looseLevel(unsigned int* unk1) = 0;
    virtual HRESULT put_looseLevel(unsigned int unk1) = 0;
    virtual HRESULT raw_Fly(tagVARIANT* unk1, int unk2) = 0;
};
