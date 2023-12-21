#pragma once

#include <iostream>
template <typename T, typename K>
void    iter(T *address, size_t length, void (*operation)(K &elem)) {
    if (!address)
        return ;
    for (size_t i = 0; i < length; i++) {
        operation(address[i]);
    }
}