#include "iter.hpp"

template <typename T>
void    print(T &elem) {
    std::cout << elem << " \"" << typeid(elem).name() << "\"" << std::endl;
}

int main() {
    int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float floatArr[5] = {1.5, 1.6, 1.7, 1.8, 1.9};
    std::string strArr[3] = {"hey", "it's", "working"};
    iter(intArr, 10, print);
    iter(floatArr, 5, print);
    iter(strArr, 3, print);
    return (0);
}