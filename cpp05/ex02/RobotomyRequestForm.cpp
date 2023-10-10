
#include "RobotomyRequestForm.hpp"

//Canonical form________________________________________
RobotomyRequestForm::RobotomyRequestForm (void)
{
	printMessage(std::cout, "RobotomyRequestForm default constructor called", GREEN);
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm& src):
AForm(src),
_target(src._target)
{
	printMessage(std::cout, "RobotomyRequestForm copy constructor called", BLUE);
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& rhs)
{
	printMessage(std::cout, "RobotomyRequestForm copy assignment operator called", BLUE);
	if (this == &rhs)
		return *this;
	AForm::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm (void)
{
	printMessage(std::cout, "RobotomyRequestForm destructor called", YELLOW);
}

//parametric constructor________________________________________________
RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
AForm("Robotomy request form", 72, 45),
_target(target)
{
	printMessage(std::cout, "RobotomyRequestForm parametric constructor called", GREEN);
	checkGradeRange(this->getReqGradeToSign());
	checkGradeRange(this->getReqGradeToExe());
}


//FORCED member functions________________________________________________
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		printMessage(std::cout, "Error: Form not signed!", RED);
	else if ((executor.getGrade() <= this->getReqGradeToExe()))
	{
		std::cout << "🛠️🔩🔊🛠️🔩🔊 (drilling noise)" << std::endl;
		std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
	}
	else
	{
		std::cout << "🤖 robotomy failed. MANUAL LABOR ✊✊✊!" << std::endl;
		throw AForm::GradeTooLowException();
	}
}


//getters________________________________________________________________
std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}



