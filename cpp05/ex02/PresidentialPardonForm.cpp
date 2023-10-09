
#include "PresidentialPardonForm.hpp"

//Canonical form________________________________________
PresidentialPardonForm::PresidentialPardonForm (void)
{
	printMessage(std::cout, "PresidentialPardonForm default constructor called", GREEN);
}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm& src):
AForm(src),
_target(src._target)
{
	printMessage(std::cout, "PresidentialPardonForm copy constructor called", BLUE);
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& rhs)
{
	printMessage(std::cout, "PresidentialPardonForm copy assignment operator called", BLUE);
	if (this == &rhs)
		return *this;
	AForm::operator=(rhs);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm (void)
{
	printMessage(std::cout, "PresidentialPardonForm destructor called", YELLOW);
}

//parametric constructor________________________________________________
PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
AForm("Presidential pardon creation form", 25, 5),
_target(target)
{
	printMessage(std::cout, "PresidentialPardonForm parametric constructor called", GREEN);
	checkGradeRange(this->getReqGradeToSign());
	checkGradeRange(this->getReqGradeToExe());
}

//FORCED member functions________________________________________________
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		printMessage(std::cout, "Error: Form not signed!", RED);
	else if ((executor.getGrade() <= this->getReqGradeToExe()))
	{
		std::cout << this->getTarget() << " has been pardoned by by Zaphod Beeblebrox 🧻" << std::endl;
	}
	else
		throw GradeTooLowException();
}


//getters________________________________________________________________
std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}



