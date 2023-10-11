
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

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
	//catch (AForm::GradeTooLowException& e) // specific catch
	//{
	//	std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	//}
}

void deepCopyTest()
{
	//int i = 10;

	ShrubberyCreationForm f1("SKRRRRT");
	std::cout << "Target: " << f1.getTarget() << std::endl;
	LINE;
	
	ShrubberyCreationForm f2(f1);
	std::cout << "Target: " << f2.getTarget() << std::endl;
	
	LINE;
	ShrubberyCreationForm f3("SOME BULLSHIOT");
	std::cout << "Target: " << f3.getTarget() << std::endl;
	f3 = f2;
	std::cout << "Target: " << f3.getTarget() << std::endl; //wont change since its const
}


void formExecutionTest()
{
	LINE;
	printMessage(std::cout, "form execution test", BLUE);
	Bureaucrat boss("Me", 1);
	Bureaucrat noob("noob", 136);

	AForm *f1_PTR = new ShrubberyCreationForm("Backyard");
	std::cout << *f1_PTR;
	f1_PTR->beSigned(boss); //comment this out to see Error if not signed
	f1_PTR->execute(noob);
	//f1_PTR->execute(boss);
}

void formBureaucratExecutionTest()
{
	LINE;
	printMessage(std::cout, "form execution test from bureaucrat", BLUE);

	Bureaucrat boss("Me", 1);
	Bureaucrat noob("noob", 138);

	AForm *f1_PTR = new RobotomyRequestForm("Backyard");
	f1_PTR->beSigned(boss); //comment this out to see Error if not signed
	std::cout << *f1_PTR;
	
	boss.executeForm(*f1_PTR);
	noob.executeForm(*f1_PTR);
}

void subject(const std::string &formName, const std::string &target)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm(formName, target);
		Bureaucrat boss("boss", 1);
		rrf->beSigned(boss);
		rrf->execute(boss);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string in = argv[1];
	try
	{
		if (in == "0")
			subject("shrubbery creation", "Garten");
		if (in == "1")
			subject("robotomy request", "Bender");
		if (in == "2")
			subject("presidential pardon", "42 vienna");
		if (in == "3")
			subject("some form that doesnt exist", "blub");
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
	return 0;
}