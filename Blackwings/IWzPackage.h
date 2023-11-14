#pragma once

class IWzPackage : public IWzNameSpace {
public:
    virtual HRESULT __stdcall raw_Init(wchar_t* unk1, wchar_t* unk2, IWzSeekableArchive* unk3) = 0;
};
