#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(PresidentialPardonForm& ref);
        PresidentialPardonForm& operator=(PresidentialPardonForm& ref);
        ~PresidentialPardonForm();
        void beSigned(Bureaucrat &bureaucrat);
};

# endif