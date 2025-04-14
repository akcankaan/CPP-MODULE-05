#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();

        Bureaucrat(const std::string& name, int grade);

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(AForm &form);
        void executeForm(AForm const& form) const;

        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
