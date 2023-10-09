
#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
private:
	RobotomyRequestForm(void);

	const std::string	_target;
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator = (const RobotomyRequestForm& rhs);
	~RobotomyRequestForm(void);

	void execute(Bureaucrat const & executor) const;
	std::string getTarget(void) const;
};
