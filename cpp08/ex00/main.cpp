#include "easyfind.hpp"
#include <iterator>

int main() {
    std::vector<int> vec;
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }
    std::vector<int>::const_iterator begin = vec.begin();
    std::vector<int>::const_iterator it = easyFind(vec, 4);
    if (it != vec.end()) {
        std::cout << *it << " found at index : " << std::distance(begin, it) << std::endl;
    } else {
        std::cout << "Iterator not found" << std::endl;
    }
    return 0;
}

