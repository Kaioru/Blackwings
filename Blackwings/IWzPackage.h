#pragma once

struct IWzPackage : IWzNameSpace {
public:
    virtual HRESULT raw_Init(wchar_t* unk1, wchar_t* unk2, IWzSeekableArchive* unk3) = 0;
};
