template <typename T>
struct ZXString {
public:
	T* _m_pStr;

public:
    ZXString<T>* Format(const char* sFormat, ...);
	void Assign(const char* s, int n);
};

typedef ZXString<char>*(* pFormat)(ZXString<char>* pThis, const char* sFormat, char* argList);
typedef void(__fastcall* pAssign)(ZXString<char>* pThis, void* edx, const char* s, int n);

static_assert(sizeof(ZXString<char>) == 0x4, "Invalid ZXString size");
