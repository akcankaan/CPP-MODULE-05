#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
