#include "pch.h"


COutPacket::COutPacket(INT nType) {
    ((VOID(_fastcall*)(COutPacket*, PVOID, INT))0x0068D090)(this, NULL, nType);
}

VOID COutPacket::Encode1(UCHAR n) {
    ((VOID(_fastcall*)(COutPacket*, PVOID, UCHAR))0x00415360)(this, NULL, n);
}

VOID COutPacket::Encode2(USHORT n) {
    ((VOID(_fastcall*)(COutPacket*, PVOID, USHORT))0x0042CA10)(this, NULL, n);
}

VOID COutPacket::Encode4(UINT n) {
    ((VOID(_fastcall*)(COutPacket*, PVOID, UINT))0x004153B0)(this, NULL, n);
}

VOID COutPacket::SendPacket() {
    ((VOID(__cdecl*)(const COutPacket*))0x00429B80)(this);
}
