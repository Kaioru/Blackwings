#include "ZXString.h"
#include "../Addresses.h"

template struct ZXString<char>;

auto cAssign = reinterpret_cast<pAssign>(ADDR_ZXSTRING__ASSIGN);

void ZXString<char>::Assign(const char* s, int n) {
    return cAssign(this, this, s, n);
}
