#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Unnamed"), isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(const std::string &n, int sGrade, int eGrade)
    : name(n), isSigned(false), signGrade(sGrade), execGrade(eGrade)
{
    if (sGrade < 1 || eGrade < 1)
        throw Form::GradeTooHighException(); // `Form::` ekliyoruz
    if (sGrade > 150 || eGrade > 150)
        throw Form::GradeTooLowException(); // `Form::` ekliyoruz
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > signGrade)
        throw Form::GradeTooLowException(); // `Form::` ekliyoruz
    isSigned = true;
}

// Exceptions with `Form::` prefix
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form: " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade();
    return os;
}
