#pragma once

class COutPacket {
public:
    INT m_bLoopback;
    UCHAR* m_aSendBuff;
    UINT m_uOffset;
    INT m_bIsEncryptedByShanda;

    COutPacket(INT nType);

    VOID Encode1(UCHAR n);
    VOID Encode2(USHORT n);
    VOID Encode4(UINT n);

    // EncodeStr
    // EncodeBuffer

    VOID SendPacket();
};
