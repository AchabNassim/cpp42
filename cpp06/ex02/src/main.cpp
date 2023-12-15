#include "Base.hpp"

int main () {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << rand() % 3 << std::endl;
}