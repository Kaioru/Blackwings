#pragma once

struct IWzSoundState;
struct IWzSound : IWzSerialize {
public:
    virtual HRESULT raw_GlobalInit(tagVARIANT unk1, tagVARIANT unk2, tagVARIANT unk3, tagVARIANT unk4) = 0;
    virtual HRESULT raw_GlobalClose() = 0;
    virtual HRESULT raw_GlobalSetBuffer(unsigned int unk1, unsigned int unk2) = 0;
    virtual HRESULT get_globalVolume(int* unk1) = 0;
    virtual HRESULT put_globalVolume(int unk1) = 0;
    virtual HRESULT get_allSoundStates(IEnumVARIANT** unk1) = 0;
    virtual HRESULT get_globalFocus(int* unk1) = 0;
    virtual HRESULT put_globalFocus(int unk1) = 0;
    virtual HRESULT raw_Play(tagVARIANT unk1, tagVARIANT unk2, IWzSoundState** unk3) = 0;
    virtual HRESULT get_length(int* unk1) = 0;
    virtual HRESULT get_type(wchar_t** unk1) = 0;
    virtual HRESULT raw_GetSourceBuffer(unsigned __int8** unk1, unsigned int* unk2) = 0;
};
