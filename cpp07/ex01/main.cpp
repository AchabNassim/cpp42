#include "iter.hpp"

template <typename T>
void    change(T &elem) {
    std::cout << elem << std::endl;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iter(arr, 10, change);
    return (0);
}