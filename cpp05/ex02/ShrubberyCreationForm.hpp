
#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	ShrubberyCreationForm(void);

	const std::string	_target;
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm(void);

	void execute(Bureaucrat const & executor) const;
	std::string getTarget(void) const;
};
