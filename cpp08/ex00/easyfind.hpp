#pragma once

#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::const_iterator easyFind(const T& Container, int occurence) {
    typename T::const_iterator it = std::find(Container.begin(), Container.end(), occurence);
    return (it);
}
