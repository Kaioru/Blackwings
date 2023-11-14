#pragma once

class IWzPackageWriter : public IWzNameSpaceWriter {
public:
    virtual HRESULT __stdcall raw_Flush(wchar_t* unk1, IWzSeekableArchive* unk2) = 0;
};
