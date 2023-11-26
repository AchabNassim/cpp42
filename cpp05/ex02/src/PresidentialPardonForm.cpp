#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>
#include <sys/syslimits.h>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& ref) : AForm(ref.getName(), 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void    PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
    if (this->getIsSigned() && this->getExecGrade() >= bureaucrat.getGrade()) {
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else {
        throw GradeTooLowException();
    }
}
