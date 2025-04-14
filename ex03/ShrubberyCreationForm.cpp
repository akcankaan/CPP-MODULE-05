#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    // ASCII ağaç çizimi
    std::string tree =
        "   *   \n"
        "  ***  \n"
        " ***** \n"
        "*******\n"
        "   |   \n";

    // Dosyayı açıp ağaç çizimini yazıyoruz
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << tree;
        file.close();
        std::cout << "Shrubbery created for " << target << std::endl;
    } else {
        std::cout << "Failed to create shrubbery file for " << target << std::endl;
    }
}
