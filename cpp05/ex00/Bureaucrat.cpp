
#include "Bureaucrat.hpp"




//Canonical form
Bureaucrat::Bureaucrat (void)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat (const Bureaucrat& src):
_name(src._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& rhs)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat (void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

//parametric constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name)
{
    std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < BEST_GRADE) 
		throw Bureaucrat::GradeTooLowException();
	else if (WORST_GRADE < grade)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::upGrade()
{
	if (_grade == BEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::downGrade()
{
	if (_grade == WORST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade++;

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high get vacation!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, work work work!");
}

std::ostream& operator << (std::ostream& stream, const Bureaucrat& rhs)
{
    stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (stream);
}

