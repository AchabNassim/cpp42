#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   name;
        bool                _signed;
        const int           sign_grade;
        const int           exec_grade;
    public :
        Form(std::string name, int sign_grade, int exec_grade);
        Form(Form &ref);
        ~Form();

        // Getters ********
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        // Setter ********
        void    setSigned(bool status);

        // Other member function ********
        void    beSigned(Bureaucrat &Bureaucrat);

        // Overload ********      
        Form& operator=(Form &ref);
};

std::ostream& operator<<(std::ostream &os, Form &form);

#endif