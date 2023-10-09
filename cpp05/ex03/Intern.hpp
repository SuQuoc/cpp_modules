
#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern& src);
	Intern& operator = (const Intern& rhs);
	~Intern(void);

	AForm* makeForm(const std::string& formName, const std::string& target);
};
