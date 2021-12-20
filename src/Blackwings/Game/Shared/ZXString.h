template <typename T>
struct ZXString {
public:
	T* _m_pStr;

public:
	void Assign(const char* s, int n);
};

typedef void(__fastcall* pAssign)(ZXString<char>* pThis, void* edx, const char* s, int n);

static_assert(sizeof(ZXString<char>) == 0x4, "Invalid ZXString size");
