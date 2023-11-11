#pragma once

class Memory {
public:
    template <typename T>
    static VOID Read(DWORD dwAddress, T* value);

    template <typename T>
    static VOID Write(DWORD dwAddress, T value);
};
