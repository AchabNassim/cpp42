#include "easyfind.hpp"
#include <iterator>

int main() {
    std::vector<int> vector;
    for (int i = 0; i < 10; i++) {
        vector.push_back(i);
    }
    std::vector<int>::const_iterator begin = vector.begin();
    std::vector<int>::const_iterator it = easyFind(vector, 4);

    if (it != vector.end()) {
        std::cout << *it << " found in container at position " << std::distance(begin, it) << std::endl;
    } else {
        std::cout << "Element not found in container";
    }

    return 0;
}

