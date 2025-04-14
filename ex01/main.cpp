#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat a("Alice", 50);
    Form f1("Tax Form", 100, 50);
    Form f2("Secret Doc", 20, 10);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    a.signForm(f1);
    a.signForm(f2);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    return 0;
}