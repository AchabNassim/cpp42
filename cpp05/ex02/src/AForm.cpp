#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

AForm::AForm() : name("Unkown"), _signed(false), sign_grade(1), exec_grade(1) {
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
    if (sign_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (sign_grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (exec_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (exec_grade < 1)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(AForm &ref) : name(ref.name), _signed(ref._signed), sign_grade(ref.sign_grade), exec_grade(ref.exec_grade) {
}

AForm::~AForm() {
}

// ************************** GETTERS

std::string AForm::getName() const {
    return (this->name);
}

bool AForm::getIsSigned() const {
    return (this->_signed);
}

int AForm::getSignGrade() const {
    return (this->sign_grade);
}

int AForm::getExecGrade() const {
    return (this->exec_grade);
}

// ************************** Setter

void    AForm::setSigned(bool status) {
    this->_signed = status;
}

// ************************** Methods

void    AForm::beSigned(Bureaucrat &bureaucrat) {
    if (this->sign_grade >= bureaucrat.getGrade()) {
        setSigned(true);
    }
    else {
        setSigned(false);
        throw Bureaucrat::GradeTooLowException();
    }
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