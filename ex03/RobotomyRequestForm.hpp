#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		const std::string target;
	public:
		RobotomyRequestForm(const std::string& target);
		virtual ~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const;
};

#endif
