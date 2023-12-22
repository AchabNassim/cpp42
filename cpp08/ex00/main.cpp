#include "easyfind.hpp"
#include <array>
#include <iterator>

int main() {
    std::array<int, 10> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10>::const_iterator begin = array.begin();
    std::array<int, 10>::const_iterator it = easyFind(array, 1);

    if (it != array.end()) {
        std::cout << *it << " found in container at position " << std::distance(begin, it) << std::endl;
    } else {
        std::cout << "Element not found in container";
    }

    return 0;
}

