
#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
private:
	PresidentialPardonForm(void);

	const std::string	_target;
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm& operator = (const PresidentialPardonForm& rhs);
	~PresidentialPardonForm(void);

	void execute(Bureaucrat const & executor) const;
	std::string getTarget(void) const;
};
