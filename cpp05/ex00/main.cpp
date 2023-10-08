
#include "Bureaucrat.hpp"
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void up_down_grade_test(void)
{
	Bureaucrat b3("Hao der lazyass", 150);
	std::cout << b3 << std::endl; 
	try
	{
		//b3.upGrade();
		b3.downGrade();
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << RED << "1st catch: " << e.what() << std::endl << RESET;
		exit(1);
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << RED << "2nd catch: " << e.what() << std::endl << RESET;
		exit(1);
	}
	std::cout << b3 << std::endl;
}

void copy_const_test(void)
{
	Bureaucrat b1("Michael", 1);
	std::cout << b1 << std::endl;

	Bureaucrat b2 = b1;
	std::cout << b2 << std::endl;

	Bureaucrat b3("Gordon", 133);
	std::cout << b3 << std::endl;

	b3 = b1;
	std::cout << b3 << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] == 'c' && argv[1][1] == '\0')
		copy_const_test();
	else if (argc == 2 && argv[1][0] == 'x' && argv[1][1] == '\0')
		up_down_grade_test();
	if (argc != 3)
		return 1;
	
	const std::string name = argv[1];
	int grade = atoi(argv[2]);

	try
	{
		Bureaucrat b1(name, grade);
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << RED << "1st catch: " << e.what() << std::endl << RESET;
		return 1;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << RED << "2nd catch: " << e.what() << std::endl << RESET;
		return 1;
	}
}