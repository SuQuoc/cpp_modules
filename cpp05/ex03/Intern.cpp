
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
	return const_cast<Intern&>(rhs);
}

Intern::~Intern (void)
{
	printMessage(std::cout, "Intern destructor called", YELLOW);
}


//utils for member functions______________________________________
int resolveForm(const std::string& formName)
{
	std::string forms[] = 
	{
		"shrubbery creation", 
		"robotomy request",
		"presidential pardon"
	};

    int num_strings = sizeof(forms) / sizeof(forms[0]);
    for (int i = 0; i < num_strings; ++i) 
	{
        if (forms[i] == formName)
			return i + 1;
    }
	return 0;
}

//member functions________________________________________________
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm* formPTR;

	switch(resolveForm(formName))
	{
		case 1:
			formPTR = new ShrubberyCreationForm(target);
			break;
		case 2:
			formPTR = new RobotomyRequestForm(target);
			break;
		case 3:
			formPTR = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Requested form doesnt exist" << std::endl;
			throw FormNonExistentException();
	}
	std::cout << "Intern creates " << formPTR->getName() << std::endl;
	return formPTR;
}

const char* Intern::FormNonExistentException::what() const throw()
{
	return ("Requested form doesnt exist");
}
