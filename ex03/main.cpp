#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
    AForm* f4 = someRandomIntern.makeForm("invalid form", "Oops");

    if (f1) {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2) {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    if (f3) {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    delete f4; // nullptr ise sorun yok

    return 0;
}
