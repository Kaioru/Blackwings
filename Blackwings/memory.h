#pragma once

class Memory {
public:
    static void WriteByte(DWORD dwAddress, BYTE cValue);
    static void WriteShort(DWORD dwAddress, SHORT nValue);
    static void WriteInt(DWORD dwAddress, INT iValue);
    static void WriteLong(DWORD dwAddress, LONG lValue);
};
