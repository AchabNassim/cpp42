#pragma once

#include <iostream>

template <typename T>
void    iter(T *address, T length, void (*operation)(T &elem)) {
    if (!address)
        return ;
    for (int i = 0; i < length; i++) {
        operation(address[i]);
    }
}