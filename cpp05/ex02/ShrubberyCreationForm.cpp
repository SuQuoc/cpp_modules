
#include "ShrubberyCreationForm.hpp"

//Canonical form________________________________________
ShrubberyCreationForm::ShrubberyCreationForm (void)
{
	printMessage(std::cout, "ShrubberyCreationForm default constructor called", GREEN);
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm& src):
AForm(src)
{
	printMessage(std::cout, "ShrubberyCreationForm copy constructor called", BLUE);
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& rhs)
{
	printMessage(std::cout, "ShrubberyCreationForm copy assignment operator called", BLUE);
	if (this == &rhs)
		return *this;
	AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm (void)
{
	printMessage(std::cout, "ShrubberyCreationForm destructor called", YELLOW);
}

//parametric constructor________________________________________________
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("Shrubbery creation form", 145, 137),
_target(target)
{
	printMessage(std::cout, "ShrubberyCreationForm parametric constructor called", GREEN);
	checkGradeRange(this->getReqGradeToSign());
	checkGradeRange(this->getReqGradeToExe());
}


//FORCED member functions________________________________________________
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getReqGradeToExe())
		{
			printMessage(std::cout, "BAUSTELLE ...", RED);
		}
		else
			throw GradeTooLowException();
	}
	else
		printMessage(std::cout, "Error: Form not signed!", RED);
}

