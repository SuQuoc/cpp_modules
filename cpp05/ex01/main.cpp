
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#define LINE    std::cout << BLUE << "---------------------------" << RESET << std::endl;


void outOfBoundsForm()
{
	LINE;
	printMessage(std::cout, "outOfBoundsForm", BLUE);
	Form f1("AMS Antrag", 0, 1);
	//Form f1("AMS Antrag", 151, 10);
	//Form f1("AMS Antrag", 10, -10);
	//Form f1("AMS Antrag", 10, 1110);
}

void signingTest()
{
	LINE;
	printMessage(std::cout, "signingTest", BLUE);
	Bureaucrat b1("Michi", 10);
	Bureaucrat b2("Michi2", 9);
	Bureaucrat b3("Stefan", 11);

	Form f1("AMS Antrag", 10, 50);
	f1.beSigned(b1);
	f1.beSigned(b2);
	f1.beSigned(b3);
}


void testFrameWork(void (*funcPTR)())
{
	if (funcPTR == NULL)
		std::cerr << RED << "Error: Invalid pointer" << std::endl << RESET;
	try
	{
		funcPTR();
	}
	catch (std::exception& e) // generic catch
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
	catch (GradeTooHighException& e) // specific catch
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}

int main()
{
	testFrameWork(outOfBoundsForm); 
	// deconstructur isnt called cuz of the throw  
	// -> nothing to destroy if nothing was build.
	testFrameWork(signingTest);
	// Form f1("AMS Antrag", 10, 1);
	// std::cout << f1;
}