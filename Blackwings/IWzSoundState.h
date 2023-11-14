#pragma once

class IWzSoundState : public IUnknown {
public:
    virtual HRESULT __stdcall get_parentSound(IWzSound** unk1) = 0;
    virtual HRESULT __stdcall get_playing(int* unk1) = 0;
    virtual HRESULT __stdcall put_playing(int unk1) = 0;
    virtual HRESULT __stdcall get_chain(tagVARIANT* unk1) = 0;
    virtual HRESULT __stdcall put_chain(tagVARIANT unk1) = 0;
    virtual HRESULT __stdcall get_chainValue(int* unk1) = 0;
    virtual HRESULT __stdcall put_chainValue(int unk1) = 0;
    virtual HRESULT __stdcall get_volume(int* unk1) = 0;
    virtual HRESULT __stdcall put_volume(int unk1) = 0;
    virtual HRESULT __stdcall raw_MoveVolume(int unk1, int unk2) = 0;
};
