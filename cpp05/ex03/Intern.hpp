
#pragma once

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	Intern(const Intern& src);
	Intern& operator = (const Intern& rhs);

public:
	Intern(void);
	~Intern(void);

	AForm* makeForm(const std::string& formName, const std::string& target);

	class FormNonExistentException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


