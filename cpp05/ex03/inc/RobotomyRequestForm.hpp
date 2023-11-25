#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(RobotomyRequestForm& ref);
        RobotomyRequestForm& operator=(RobotomyRequestForm& ref);
        ~RobotomyRequestForm();
        void beSigned(Bureaucrat &bureaucrat);
};

# endif