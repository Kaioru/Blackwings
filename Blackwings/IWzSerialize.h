#pragma once

struct IWzArchive;
struct IWzSerialize : IUnknown {
public:
    virtual HRESULT get_persistentUOL(wchar_t** unk1) = 0;
    virtual HRESULT raw_Serialize(IWzArchive* unk1) = 0;
};
