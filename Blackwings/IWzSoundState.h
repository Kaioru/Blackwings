#pragma once

struct IWzSoundState : IUnknown {
public:
    virtual HRESULT get_parentSound(IWzSound** unk1) = 0;
    virtual HRESULT get_playing(int* unk1) = 0;
    virtual HRESULT put_playing(int unk1) = 0;
    virtual HRESULT get_chain(tagVARIANT* unk1) = 0;
    virtual HRESULT put_chain(tagVARIANT unk1) = 0;
    virtual HRESULT get_chainValue(int* unk1) = 0;
    virtual HRESULT put_chainValue(int unk1) = 0;
    virtual HRESULT get_volume(int* unk1) = 0;
    virtual HRESULT put_volume(int unk1) = 0;
    virtual HRESULT raw_MoveVolume(int unk1, int unk2) = 0;
};
