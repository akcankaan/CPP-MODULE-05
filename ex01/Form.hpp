#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat; // forward declaration

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string &name, int signGrade, int execGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
