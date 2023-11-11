#pragma once

class Memory {
public:
    static VOID WriteByte(DWORD dwAddress, BYTE cValue);
    static VOID WriteShort(DWORD dwAddress, SHORT nValue);
    static VOID WriteInt(DWORD dwAddress, INT iValue);
    static VOID WriteLong(DWORD dwAddress, LONG lValue);
};
