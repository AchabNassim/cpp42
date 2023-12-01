#include "../inc/Intern.hpp"

Intern::Intern() {
}

// Intern::Intern(Intern& ref) {
// }

Intern::~Intern() {
}

Intern& Intern::operator=(Intern &ref) {
    if (this != &ref)
        return (*this);
    return (*this);
}

void    delete_forms(AForm** forms, int index) {
    for (int i = 0; i < 3; i++) {
        if (i != index)
            delete forms[i];
    }
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    int     index = 0;
    AForm* requestedForm;
    for (int i = 0; i < 3; i++) {
        if (formName.compare(formNames[i]) == 0)
            break ;
    }
    switch (index) {
        case 0:
            requestedForm = forms[0];
            delete_forms(forms, 0);
            return (requestedForm);
        case 1:
            requestedForm = forms[1];
            delete_forms(forms, 1);
            return (requestedForm);
        case 2:
            requestedForm = forms[2];
            delete_forms(forms, 2);
            return (requestedForm);
        default:
            delete_forms(forms, -1);
            std::cout << "Form requested doesn't exist" << std::endl;
    }
    return (NULL);
}