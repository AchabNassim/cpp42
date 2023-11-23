#include "Bureaucrat.hpp"
#include <exception>

int main() {
    try {
        Bureaucrat boss("Laarbi", 1);
        boss.incrementGrade();
        std::cout << boss;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}