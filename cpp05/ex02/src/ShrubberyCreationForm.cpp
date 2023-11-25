#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>
#include <sys/syslimits.h>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& ref) : AForm(ref.getName(), 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void    ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat) {
    if (this->getSignGrade() >= bureaucrat.getGrade() && this->getExecGrade() >= bureaucrat.getGrade()) {
        setSigned(true);
        signForm(bureaucrat, *this);
        std::ofstream file(this->getName());
        file << "        ^\n"
                "       ^^^\n"
                "      ^^^^^\n"
                "     ^^^^^^^\n"
                "    ^^^^^^^^^\n"
                "   ^^^^^^^^^^^\n"
                "  ^^^^^^^^^^^^^\n"
                " ^^^^^^^^^^^^^^^\n"
                "^^^^^^^^^^^^^^^^^\n"
                "       |||\n";
    }
    else {
        setSigned(false);
        signForm(bureaucrat,  *this);
        throw GradeTooLowException();
    }
}