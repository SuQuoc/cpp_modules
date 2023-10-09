
# include "ShrubberyCreationForm.hpp"

#define LINE    std::cout << BLUE << "---------------------------" << RESET << std::endl;

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

void deepCopyTest()
{
	//int i = 10;

	ShrubberyCreationForm f1("TARGET SKRRRRT");
	std::cout << f1;
	LINE;
	
	ShrubberyCreationForm f2(f1);
	std::cout << f1;
	
	LINE;
	ShrubberyCreationForm f3("SOME BULLSHIOT");
	std::cout << f1;
	
	f3 = f2;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string in = argv[1];
	if (in == "1")
		testFrameWork(deepCopyTest);
	return 0;
}