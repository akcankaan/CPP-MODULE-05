#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::srand(std::time(0));
    int success = std::rand() % 2;

    std::cout << "Drilling noises...\n";
    if (success) {
        std::cout << target << " has been robotomized successfully!\n";
    } else {
        std::cout << "Robotomy failed on " << target << "!\n";
    }
}
