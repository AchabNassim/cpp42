#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

// ************************** CONSTRUCTORS

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat &ref) : name(ref.name), grade(ref.grade) {
}

Bureaucrat::~Bureaucrat() {
}

// ************************** OVERLOAD

Bureaucrat& Bureaucrat::operator=(Bureaucrat &ref) {
    if (this == &ref)
        return (*this);
    this->grade = ref.grade;
    return (*this);
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (os);
}

// ************************** GETTERS

std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}
// ************************** SETTERS

void    Bureaucrat::setGrade(int newGrade) {
    if (this->grade < 1)
        throw GradeTooHighException();
    else if (this->grade > 150)
        throw GradeTooLowException();
    this->grade = newGrade;
}

void    Bureaucrat::incrementGrade() {
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void    Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}


void    Bureaucrat::signForm(Bureaucrat &bureaucrat, Form &form) {
    if (form.getIsSigned()) {
        std::cout << bureaucrat << " signed " << form << std::endl;
    } else {
        std::cout << bureaucrat << " couldn't sign " << form << " Because grade is too low" << std::endl; 
    }
}
