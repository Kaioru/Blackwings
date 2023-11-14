#pragma once

template <typename T>
struct _com_ptr_t {
public:
    T* m_pInterface;

    _com_ptr_t();
    ~_com_ptr_t();

    T* operator*();
    T* operator->();
};
