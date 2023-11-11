#include "pch.h"

void Memory::WriteByte(DWORD dwAddress, BYTE cValue) 
{
    *(BYTE*)dwAddress = cValue;
}

void Memory::WriteShort(DWORD dwAddress, SHORT sValue)
{
    *(SHORT*)dwAddress = sValue;
}

void Memory::WriteInt(DWORD dwAddress, INT iValue) 
{
    *(INT*)dwAddress = iValue;
}

void Memory::WriteLong(DWORD dwAddress, LONG lValue)
{
    *(LONG*)dwAddress = lValue;
}
