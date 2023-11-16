#include "pch.h"

UCHAR CInPacket::Decode1() {
    return ((UCHAR(_fastcall*)(CInPacket*, PVOID))0x004097D0)(this, NULL);
}

USHORT CInPacket::Decode2() {
    return ((USHORT(_fastcall*)(CInPacket*, PVOID))0x0042A2A0)(this, NULL);
}

UINT CInPacket::Decode4() {
    return ((UINT(_fastcall*)(CInPacket*, PVOID))0x00409870)(this, NULL);
}

