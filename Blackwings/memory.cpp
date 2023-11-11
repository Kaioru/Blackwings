#include "pch.h"

VOID Memory::WriteByte(DWORD dwAddress, BYTE cValue)
{
    *(BYTE*)dwAddress = cValue;
}

VOID Memory::WriteShort(DWORD dwAddress, SHORT sValue)
{
    *(SHORT*)dwAddress = sValue;
}

VOID Memory::WriteInt(DWORD dwAddress, INT iValue)
{
    *(INT*)dwAddress = iValue;
}

VOID Memory::WriteLong(DWORD dwAddress, LONG lValue)
{
    *(LONG*)dwAddress = lValue;
}
