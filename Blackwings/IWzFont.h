#pragma once

struct IWzFont : IUnknown {
public:
    virtual HRESULT raw_Create(wchar_t* unk1, unsigned int unk2, unsigned int unk3, tagVARIANT unk4) = 0;
    virtual HRESULT get_color(int* unk1) = 0;
    virtual HRESULT get_height(int* unk1) = 0;
    virtual HRESULT get_fullHeight(int* unk1) = 0;
    virtual HRESULT raw_CalcTextWidth(wchar_t* unk1, tagVARIANT unk2, unsigned int* unk3) = 0;
    virtual HRESULT raw_CalcLongestText(wchar_t* unk1, int unk2, tagVARIANT unk3, int* unk4) = 0;
    virtual HRESULT raw_CalcLongestTextForGlobal(wchar_t* unk1, int unk2, tagVARIANT unk3, int* unk4) = 0;
    virtual HRESULT raw_CalcLongestTextForGlobalEx(wchar_t* unk1, int unk2, int* unk3, tagVARIANT unk4, int* unk5) = 0;
    virtual HRESULT raw_CalcLineCountForGlobal(wchar_t* unk1, int unk2, tagVARIANT unk3, int* unk4) = 0;
    virtual HRESULT raw_DrawText(int unk1, int unk2, wchar_t* unk3, IWzCanvas* unk4, tagVARIANT unk5, tagVARIANT unk6, unsigned int* unk7) = 0;
};
