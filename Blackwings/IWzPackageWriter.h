#pragma once

struct IWzPackageWriter : IWzNameSpaceWriter {
public:
    virtual HRESULT raw_Flush(wchar_t* unk1, IWzSeekableArchive* unk2) = 0;
};
