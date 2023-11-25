#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm& ref);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& ref);
        ~ShrubberyCreationForm();
        void beSigned(Bureaucrat &bureaucrat);
};

# endif