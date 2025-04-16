#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat junior("Junior", 150);

        std::cout << boss << std::endl;
        std::cout << junior << std::endl;

        PresidentialPardonForm pardonForm("Alice");
        RobotomyRequestForm robotomyForm("Bob");
        ShrubberyCreationForm shrubberyForm("Garden");

        std::cout << pardonForm << std::endl;
        std::cout << robotomyForm<< std::endl;
        std::cout << shrubberyForm<< std::endl;

        junior.signForm(pardonForm);
        std::cout << pardonForm<< std::endl;

        boss.signForm(pardonForm);
        std::cout << pardonForm<< std::endl;

        junior.executeForm(pardonForm);
        boss.executeForm(pardonForm);

        boss.signForm(robotomyForm);
        boss.executeForm(robotomyForm);

        boss.signForm(shrubberyForm);
        boss.executeForm(shrubberyForm);

        std::cout  << "The program successfully!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
