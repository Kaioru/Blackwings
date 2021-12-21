#include <windows.h>

class Memory {
public:
    template <typename T>
    static void Read(DWORD dwAddress, T* value);

    template <typename T>
    static void Write(DWORD dwAddress, T value);
};
