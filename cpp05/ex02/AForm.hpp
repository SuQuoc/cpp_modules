
#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Bureaucrat;

class AForm
{
private: 
	const std::string	_name;
	const int			_requiredGradeToSign;
	const int			_requiredGradeToExe;
	bool				_signed;

public:
	AForm(void);
	AForm(const std::string name, const int reqGradeToSign, const int reqGradeToExe);
	AForm(const AForm& src);
	AForm& operator = (const AForm& rhs);
	virtual ~AForm(void);

	std::string getName() const;
	int getReqGradeToSign() const;
	int getReqGradeToExe() const;
	bool getSign() const;

	void beSigned(const Bureaucrat& signer);
	virtual void execute(Bureaucrat const & executor) const = 0; // NICHT SICHER OB HIER DAS PURE VIRTUAL GEHOERT

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream& stream, const AForm& rhs);
void printMessage(std::ostream& output, const std::string& msg, const std::string& color);
void checkGradeRange(const int grade);
