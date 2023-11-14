#pragma once

class IWzSoundState;
class IWzSound : public IWzSerialize {
public:
    virtual HRESULT __stdcall raw_GlobalInit(tagVARIANT unk1, tagVARIANT unk2, tagVARIANT unk3, tagVARIANT unk4) = 0;
    virtual HRESULT __stdcall raw_GlobalClose() = 0;
    virtual HRESULT __stdcall raw_GlobalSetBuffer(unsigned int unk1, unsigned int unk2) = 0;
    virtual HRESULT __stdcall get_globalVolume(int* unk1) = 0;
    virtual HRESULT __stdcall put_globalVolume(int unk1) = 0;
    virtual HRESULT __stdcall get_allSoundStates(IEnumVARIANT** unk1) = 0;
    virtual HRESULT __stdcall get_globalFocus(int* unk1) = 0;
    virtual HRESULT __stdcall put_globalFocus(int unk1) = 0;
    virtual HRESULT __stdcall raw_Play(tagVARIANT unk1, tagVARIANT unk2, IWzSoundState** unk3) = 0;
    virtual HRESULT __stdcall get_length(int* unk1) = 0;
    virtual HRESULT __stdcall get_type(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall raw_GetSourceBuffer(unsigned __int8** unk1, unsigned int* unk2) = 0;
};
