#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        // Intern(Intern& ref);
        Intern& operator=(Intern &ref);
        ~Intern();
        AForm* makeForm(std::string formName, std::string target);
};


#endif