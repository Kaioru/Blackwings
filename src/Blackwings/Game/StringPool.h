#include "Shared/ZXString.h"

struct StringPool {
private:


public:
    static StringPool* GetInstance();
    ZXString<char>* GetString(ZXString<char>* result, unsigned int nIdx, char __formal);
};

typedef StringPool* (__cdecl* pGetInstance)();
typedef ZXString<char>* (__fastcall* pGetString)(StringPool* pThis, void* edx, ZXString<char>* result, unsigned int nIdx, char __formal);

//static_assert(sizeof(StringPool) == 0x10, "Invalid StringPool size");
