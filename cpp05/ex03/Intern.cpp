
#include "Intern.hpp"

//Canonical form________________________________________
Intern::Intern (void)
{
	printMessage(std::cout, "Intern default constructor called", GREEN);
}

Intern::Intern (const Intern& src)
{
	printMessage(std::cout, "Intern copy constructor called", BLUE);
	*this = src;
}

Intern& Intern::operator = (const Intern& rhs)
{
	printMessage(std::cout, "Intern copy assignment operator called", BLUE);
	return *this;
}

Intern::~Intern (void)
{
	printMessage(std::cout, "Intern destructor called", YELLOW);
}


//member functions________________________________________________
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm* formPTR;

	switch()
	{
		case 1:
			formPTR = new ShrubberyCreationForm(target);
			return formPTR;
		case 2:
			formPTR = new RobotomyRequestForm(target);
			return formPTR;
		case 3:
			formPTR = new PresidentialPardonForm(target);
			return formPTR;
		default:
			std::cout << "Requested form doesnt exist" << std::endl;
			return (NULL);
	}
}


