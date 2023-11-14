#pragma once

class IWzFileSystem : public IWzWritableNameSpace {
public:
    virtual HRESULT __stdcall raw_Init(wchar_t* unk1) = 0;
};
