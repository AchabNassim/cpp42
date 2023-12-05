#include "ScalarConverter.hpp"
#include <iomanip>

int main() {
    ScalarConverter::convert("50000000");
    float nb = 5;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << nb << std::endl;
    return (0);
}