#include <stdarg.h>

#include "ZXString.h"
#include "../Addresses.h"

template struct ZXString<char>;

auto oFormat = reinterpret_cast<pFormat>(ADDR_ZXSTRING__FORMAT);
auto oAssign = reinterpret_cast<pAssign>(ADDR_ZXSTRING__ASSIGN);

ZXString<char>* ZXString<char>::Format(const char* sFormat, ...) {
    va_list va;
    va_start(va, sFormat);
    return oFormat(this, sFormat, va);
}

void ZXString<char>::Assign(const char* s, int n) {
    return oAssign(this, this, s, n);
}
