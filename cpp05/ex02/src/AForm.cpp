#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

AForm::AForm() : name("Unkown"), _signed(false), sign_grade(1), exec_grade(1) {
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
    if (sign_grade > 150)
        throw GradeTooLowException();
    else if (sign_grade < 1)
        throw GradeTooHighException();
    if (exec_grade > 150)
        throw GradeTooLowException();
    else if (exec_grade < 1)
        throw GradeTooHighException();
}

AForm::AForm(AForm &ref) : name(ref.name), _signed(ref._signed), sign_grade(ref.sign_grade), exec_grade(ref.exec_grade) {
}

AForm::~AForm() {
}

// ************************** GETTERS

std::string AForm::getName() {
    return (this->name);
}

bool AForm::getIsSigned() {
    return (this->_signed);
}

int AForm::getSignGrade() {
    return (this->sign_grade);
}

int AForm::getExecGrade() {
    return (this->exec_grade);
}

// ************************** Setter

void    AForm::setSigned(bool status) {
    this->_signed = status;
}

// ************************** Overload

AForm& AForm::operator=(AForm &ref) {
    if (this == &ref)
        return (*this);
    this->_signed = ref._signed;
    return (*this);
}


std::ostream& operator<<(std::ostream &os, AForm &AForm) {
    os << "* form name : " << AForm  .getName() << " | signing grade : " << AForm  .getSignGrade() << " | execution grade of " << AForm  .getExecGrade() << " *";
    return (os);
}