
#include "Form.hpp"

//utils for ________________________________________
void printMessage(std::ostream& output, const std::string& msg, const std::string& color)
{
	output << color << msg << RESET << std::endl;
}

void checkGradeRange(const int grade) 
{
	if (grade < BEST_GRADE) 
		throw GradeTooLowException();
	else if (WORST_GRADE < grade)
		throw GradeTooHighException();
}

//overload of the insertion («) operator______________________
std::ostream& operator << (std::ostream& stream, const Form& rhs)
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
Form::Form (void):
_name(),
_requiredGradeToSign(),
_requiredGradeToExe()
{
	printMessage(std::cout, "Form default constructor called", GREEN);
}

Form::Form (const Form& src):
_name(src._name),
_requiredGradeToSign(src._requiredGradeToSign),
_requiredGradeToExe(src._requiredGradeToExe),
_signed(src._signed)
{
	printMessage(std::cout, "Form copy constructor called", BLUE);
	*this = src;
}

Form& Form::operator = (const Form& rhs)
{
	printMessage(std::cout, "Form copy assignment operator called", BLUE);
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed; 
	//makes no sense in this context since all other attributes stay the same
	//so this will only copy signed, which IRL i would avoid
	return *this;
}

Form::~Form (void)
{
	printMessage(std::cout, "Form destructor called", YELLOW);
}

//parametric constructor________________________________________________
Form::Form(const std::string name, const int reqGradeToSign, const int reqGradeToExe):	
_name(name),
_requiredGradeToSign(reqGradeToSign),
_requiredGradeToExe(reqGradeToExe),
_signed(false)
{
	printMessage(std::cout, "Form parametric constructor called", GREEN);
	checkGradeRange(_requiredGradeToSign);
	checkGradeRange(_requiredGradeToExe);
}


//member functions________________________________________________
void Form::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() <= this->getReqGradeToSign())
	{
		this->_signed = true;
		//printMessage(std::cout, "Form successfully signed ✅", RESET);
	}
	else
		throw GradeTooLowException();
}


//getters____________________________________________
std::string Form::getName() const
{
	return (this->_name);
}

int Form::getReqGradeToSign() const
{
	return (this->_requiredGradeToSign);
}

int Form::getReqGradeToExe() const
{
	return (this->_requiredGradeToExe);
}

bool Form::getSign() const
{
	return (this->_signed);
}



//exceptions
//const char* GradeTooHighException::what() const throw()
//{
//	return ("Grade is too high get vacation!");
//}
//
//const char* GradeTooLowException::what() const throw()
//{
//	return ("Grade is too low, work work work!");
//}
