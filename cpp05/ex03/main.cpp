#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/Intern.hpp"
#include <exception>

int main() {
    Intern Laarbi;
    AForm* form = Laarbi.makeForm("PresidentialPardonForm", "Hmed");
    std::cout << form->getName() << std::endl;
    return (0);
}