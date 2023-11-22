#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <atomic>
#include <exception>
#include <iostream>


class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat &ref);
        Bureaucrat& operator=(Bureaucrat &ref);
        Bureaucrat& operator<<(Bureaucrat &ref);
        ~Bureaucrat();
        std::string getName() const;
        std::string getGrade() const;
        void setGrade(int newGrade);
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception {
            public:
                const char *what() {
                    return ("Grade too high");
                };
        };
        class GradeTooLowException : public std::exception {
            public:
                const char *what() {
                    return ("Grade too low");
                };
        };
};

#endif