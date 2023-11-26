#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm : public Bureaucrat {
    private:
        const std::string   name;
        bool                _signed;
        const int           sign_grade;
        const int           exec_grade;
    public :
        AForm();
        AForm(std::string name, int sign_grade, int exec_grade);
        AForm(AForm &ref);
        virtual ~AForm();

        // Getters ********
        std::string getName();
        bool getIsSigned();
        int getSignGrade();
        int getExecGrade();

        // Setter ********
        void    setSigned(bool status);

        // Other member function ********
        void            beSigned(Bureaucrat &Bureaucrat);
        virtual void    execute(Bureaucrat const & executor) const = 0;

        // Overload ********      
        AForm& operator=(AForm &ref);
};

std::ostream& operator<<(std::ostream &os, AForm &form);

#endif