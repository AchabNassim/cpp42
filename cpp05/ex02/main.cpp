#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include <exception>

int main() {
    try {
        PresidentialPardonForm shruberry("LOLO");
        Bureaucrat boss("Laarbi", 10);
        shruberry.beSigned(boss);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}