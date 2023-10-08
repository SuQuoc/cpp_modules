
#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>
#include "sstream"


#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Form
{
private: 
	Form(void);
	const std::string	_name;
	const int			_requiredGradeToSign;
	const int			_requiredGradeToExe;
	bool				_signed;

public:
	Form(const std::string name, const int reqGradeToSign, const int reqGradeToExe);
	Form(const Form& src);
	Form& operator = (const Form& rhs);
	~Form(void);

	std::string getName() const;
	int getReqGradeToSign() const;
	int getReqGradeToExe() const;
	bool getSign() const;

	void beSigned(const Bureaucrat& signer);
};

std::ostream& operator << (std::ostream& stream, const Form& rhs);
void printMessage(std::ostream& output, const std::string& msg, const std::string& color);


//class GradeTooHighException: public std::exception
//{
//	public:
//		virtual const char* what() const throw();
//};
//
//
//class GradeTooLowException: public std::exception
//{
//	public:
//		virtual const char* what() const throw();
//};