#include "StringPool.h"
#include "Addresses.h"

auto cGetInstance = reinterpret_cast<pGetInstance>(ADDR_STRINGPOOL__GETINSTANCE);
auto cGetString = reinterpret_cast<pGetString>(ADDR_STRINGPOOL__GETSTRING);

StringPool* StringPool::GetInstance() {
    return cGetInstance();
}

ZXString<char>* StringPool::GetString(ZXString<char>* result, unsigned int nIdx, char __formal) {
    return cGetString(this, this, result, nIdx, __formal);
}
