#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"
#include <exception>

int main() {
    try {
        Bureaucrat boss("Laarbi", 3);
        Form form("new Law", 2, 2);
        form.beSigned(boss);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}