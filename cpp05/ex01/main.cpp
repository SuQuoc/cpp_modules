
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#define LINE    std::cout << BLUE << "---------------------------" << RESET << std::endl;

// deconstructur isnt called cuz of the throw  
// -> nothing to destroy if nothing was build.
void outOfBoundsForm()
{
	LINE;
	printMessage(std::cout, "outOfBoundsForm", BLUE);
	// Form f1("AMS Antrag", 0, 1);
	// Form f1("AMS Antrag", 1, -1);
	// Form f1("AMS Antrag", 151, 1);
	// Form f1("AMS Antrag", 1, 151);
}

void signingTest()
{
	LINE;
	printMessage(std::cout, "signingTest", BLUE);
	Bureaucrat b1("Michi", 10);
	Bureaucrat b2("Michi2", 9);
	Bureaucrat b3("Stefan", 11);

	Form f1("AMS Antrag", 10, 50);
	//f1.beSigned(b1);
	//f1.beSigned(b2);
	try
	{
		f1.beSigned(b3);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
	std::cout << f1;
}

void signingBureaucratTest()
{
	LINE;
	printMessage(std::cout, "signingTest", BLUE);
	Bureaucrat b1("Michi", 9);
	Bureaucrat b2("Claus", 50);

	Form f1("AMS Antrag", 10, 50);
	std::cout << f1;

	//b1.signForm(f1);
	//std::cout << f1;
	//LINE;

	b2.signForm(f1);
	std::cout << f1;
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

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string in = argv[1];
	if (in == "1")
		testFrameWork(outOfBoundsForm);
	else if (in == "2")
		testFrameWork(signingTest);
	else if (in == "3")
		testFrameWork(signingBureaucratTest);

	//Form f1;
	//Bureaucrat b1;
}