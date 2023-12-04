#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& ref) : AForm(ref.getName(), 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void    RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
    if (this->getIsSigned() && this->getExecGrade() >= bureaucrat.getGrade()) {
        static int successRate;
        if (successRate & 1)
            std::cout << "Robotomy failed :)\n";
        else
            std::cout << this->getName() << " had a successfull Robotomy :(\n";
        successRate++;
    }
    else {
        throw Bureaucrat::GradeTooLowException();
    }
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& ref) {
    if (this == &ref)
        return (*this);
    return (*this);
}