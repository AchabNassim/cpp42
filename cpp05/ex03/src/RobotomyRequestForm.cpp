#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>
#include <sys/syslimits.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& ref) : AForm(ref.getName(), 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void    RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat) {
    if (this->getSignGrade() >= bureaucrat.getGrade() && this->getExecGrade() >= bureaucrat.getGrade()) {
        setSigned(true);
        signForm(bureaucrat, *this);
        static int successRate;
        if (successRate & 1)
            std::cout << "Robotomy failed :)\n";
        else
            std::cout << this->getName() << " had a successfull Robotomy :(\n";
    }
    else {
        setSigned(false);
        signForm(bureaucrat,  *this);
        throw GradeTooLowException();
    }
}