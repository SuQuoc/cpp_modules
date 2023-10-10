
#include "AForm.hpp"

//utils for ________________________________________
void printMessage(std::ostream& output, const std::string& msg, const std::string& color)
{
	output << color << msg << RESET << std::endl;
}

void checkGradeRange(const int grade) 
{
	if (grade < BEST_GRADE) 
		throw AForm::GradeTooLowException();
	else if (WORST_GRADE < grade)
		throw AForm::GradeTooHighException();
}

//overload of the insertion («) operator______________________
std::ostream& operator << (std::ostream& stream, const AForm& rhs)
{
	std::ostringstream topbot;
    topbot << std::setfill('-') << std::left << std::setw(43) << "+" << "+" << std::endl;

    stream << topbot.str()
			<< std::left << std::setw(31) << "| Name:" 						<< std::left << std::setw(12) << rhs.getName() 				<< std::setw(2) << "|" << std::endl 
			<< std::left << std::setw(31) << "| Required grade to sign:" 	<< std::left << std::setw(12) << rhs.getReqGradeToSign() 	<< std::setw(2) << "|" << std::endl
			<< std::left << std::setw(31) << "| Required grade to execute:" << std::left << std::setw(12) << rhs.getReqGradeToExe() 	<< std::setw(2) << "|" << std::endl
			<< std::left << std::setw(31) << "| signed:" 					<< std::left << std::setw(12) << rhs.getSign() 				<< std::setw(2) << "|" << std::endl
    		<< topbot.str();
    return (stream);
}

//Canonical form________________________________________
AForm::AForm (void):
_name(),
_requiredGradeToSign(),
_requiredGradeToExe(),
_signed(false)
{
	printMessage(std::cout, "AForm default constructor called", GREEN);
}

AForm::AForm (const AForm& src):
_name(src._name),
_requiredGradeToSign(src._requiredGradeToSign),
_requiredGradeToExe(src._requiredGradeToExe),
_signed(src._signed)
{
	printMessage(std::cout, "AForm copy constructor called", BLUE);
	*this = src;
}

AForm& AForm::operator = (const AForm& rhs)
{
	printMessage(std::cout, "AForm copy assignment operator called", BLUE);
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed; 
	//makes no sense in this context since all other attributes stay the same
	//so this will only copy signed, which IRL i would avoid
	return *this;
}

AForm::~AForm (void)
{
	printMessage(std::cout, "AForm destructor called", YELLOW);
}

//parametric constructor________________________________________________
AForm::AForm(const std::string name, const int reqGradeToSign, const int reqGradeToExe):	
_name(name),
_requiredGradeToSign(reqGradeToSign),
_requiredGradeToExe(reqGradeToExe),
_signed(false)
{
	printMessage(std::cout, "AForm parametric constructor called", GREEN);
	checkGradeRange(_requiredGradeToSign);
	checkGradeRange(_requiredGradeToExe);
}


//member functions________________________________________________
void AForm::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() <= this->getReqGradeToSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}


//getters____________________________________________
std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getReqGradeToSign() const
{
	return (this->_requiredGradeToSign);
}

int AForm::getReqGradeToExe() const
{
	return (this->_requiredGradeToExe);
}

bool AForm::getSign() const
{
	return (this->_signed);
}

//exceptions_______________________________________
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! (form)");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! (form)");
}