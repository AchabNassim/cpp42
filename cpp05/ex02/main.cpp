#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include <exception>

int main() {
    PresidentialPardonForm pardon("LOLO");
    Bureaucrat boss("Laarbi", 1);
    boss.signForm(pardon);
    boss.executeForm(pardon);
    return (0);
}