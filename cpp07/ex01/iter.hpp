#pragma once

#include <iostream>

template <typename T>
void    iter(T *address, size_t length, void (*operation)(T &elem)) {
    if (!address)
        return ;
    for (size_t i = 0; i < length; i++) {
        operation(address[i]);
    }
}