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

void    ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
    if (this->getIsSigned() && this->getExecGrade() >= bureaucrat.getGrade()) {
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
        throw GradeTooLowException();
    }
}