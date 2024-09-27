#include "framework.h"

class Memory {
public:
    static LPVOID AddressOf(LPCSTR sModule, LPCSTR sProc);

    template <typename T>
    static VOID Read(DWORD dwAddress, T* value);

    template <typename T>
    static VOID Write(DWORD dwAddress, T value);
    static VOID WriteFill(DWORD dwAddress, BYTE cValue, SIZE_T nSize);

    static BOOL Trampoline(LPVOID* ppTarget, LPVOID pDetour);
};