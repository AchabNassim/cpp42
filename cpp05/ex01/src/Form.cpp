#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Form::Form(std::string name, int sign_grade, int exec_grade) : name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
    if (sign_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (sign_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (exec_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (exec_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Form::Form(Form &ref) : name(ref.name), _signed(ref._signed), sign_grade(ref.sign_grade), exec_grade(ref.exec_grade) {
}

Form::~Form() {
}

// ************************** GETTERS

std::string Form::getName() const {
    return (this->name);
}

bool Form::getIsSigned() const {
    return (this->_signed);
}

int Form::getSignGrade() const {
    return (this->sign_grade);
}

int Form::getExecGrade() const {
    return (this->exec_grade);
}

// ************************** Setter

void    Form::setSigned(bool status) {
    this->_signed = status;
}

// ************************** Member functions

void    Form::beSigned(Bureaucrat &bureaucrat) {
    if (this->sign_grade >= bureaucrat.getGrade()) {
        setSigned(true);
    }
    else {
        setSigned(false);
        throw Bureaucrat::GradeTooLowException();
    }
}

// ************************** Overload

Form& Form::operator=(Form &ref) {
    if (this == &ref)
        return (*this);
    this->_signed = ref._signed;
    return (*this);
}


std::ostream& operator<<(std::ostream &os, Form &form) {
    os << "Form : name " << form.getName() << " | signing grade : " << form.getSignGrade() << " | execution grade of " << form.getExecGrade();
    return (os);
}