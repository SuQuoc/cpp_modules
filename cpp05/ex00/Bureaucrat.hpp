
#pragma once

#include <iostream>

#define BEST_GRADE 	1
#define WORST_GRADE 150

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Bureaucrat
{
private: 
	Bureaucrat(void);
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator = (const Bureaucrat& rhs);
	~Bureaucrat(void);

	void upGrade();
	void downGrade();

	std::string getName() const;
	int getGrade() const;

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

std::ostream& operator << (std::ostream& stream, const Bureaucrat& rhs);
