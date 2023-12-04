#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>

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
        std::ofstream file(this->getName().c_str());
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
        throw Bureaucrat::GradeTooLowException();
    }
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& ref) {
    if (this == &ref)
        return (*this);
    return (*this);
}