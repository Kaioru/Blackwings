#pragma once

class IWzArchive;
class IWzSerialize : public IUnknown {
public:
    virtual HRESULT __stdcall get_persistentUOL(wchar_t** unk1) = 0;
    virtual HRESULT __stdcall raw_Serialize(IWzArchive* unk1) = 0;
};
