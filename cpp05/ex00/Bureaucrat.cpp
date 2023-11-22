#include "Bureaucrat.hpp"

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

// ************************** OVERLOAD




// ************************** GETTERS

std::string Bureaucrat::getName() const {
    return (this->name);
}

std::string Bureaucrat::getGrade() const {
    return (this->name);
}
// ************************** SETTERS

void    Bureaucrat::setGrade(int newGrade) {
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
    this->grade--;
}

