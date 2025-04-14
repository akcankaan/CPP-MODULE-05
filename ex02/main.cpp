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

        std::cout << pardonForm;
        std::cout << robotomyForm;
        std::cout << shrubberyForm;

        junior.signForm(pardonForm);
        std::cout << pardonForm;

        boss.signForm(pardonForm);
        std::cout << pardonForm;

        junior.executeForm(pardonForm);
        boss.executeForm(pardonForm);

        boss.signForm(robotomyForm);
        boss.executeForm(robotomyForm);

        boss.signForm(shrubberyForm);
        boss.executeForm(shrubberyForm);

        std::cout  << "The program successfully!" << std::endl;
        Bureaucrat deneme("ben", 0);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
