#pragma once

struct IWzFileSystem : IWzWritableNameSpace {
public:
    virtual HRESULT raw_Init(wchar_t* unk1) = 0;
};
