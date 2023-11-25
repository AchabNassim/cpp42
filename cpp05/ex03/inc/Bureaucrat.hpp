#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <atomic>
#include <exception>
#include <iostream>
#include <ostream>

class AForm;

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat &ref);
        Bureaucrat& operator=(Bureaucrat &ref);
        ~Bureaucrat();

        // Getters ********
        std::string getName() const;
        int getGrade() const;

        // Setters ********
        void setGrade(int newGrade);
        void incrementGrade();
        void decrementGrade();

        // Exceptions ********
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        // Other member function ********
        void    signForm(Bureaucrat &bureaucrat, AForm &form);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &bureaucrat);

#endif