
#include "ShrubberyCreationForm.hpp"

//Canonical form________________________________________
ShrubberyCreationForm::ShrubberyCreationForm (void)
{
	printMessage(std::cout, "ShrubberyCreationForm default constructor called", GREEN);
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm& src):
AForm(src),
_target(src._target)
{
	printMessage(std::cout, "ShrubberyCreationForm copy constructor called", BLUE);
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& rhs)
{
	printMessage(std::cout, "ShrubberyCreationForm copy assignment operator called", BLUE);
	if (this == &rhs)
		return *this;
	AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm (void)
{
	printMessage(std::cout, "ShrubberyCreationForm destructor called", YELLOW);
}

//parametric constructor________________________________________________
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("Shrubbery creation form", 145, 137),
_target(target)
{
	printMessage(std::cout, "ShrubberyCreationForm parametric constructor called", GREEN);
	checkGradeRange(this->getReqGradeToSign());
	checkGradeRange(this->getReqGradeToExe());
}

//Form specific execution________________________________________________
void printTree(std::ofstream& outputFile, int height) 
{
    // Print the tree
    for (int i = 0; i < height; ++i) 
	{
        for (int j = 0; j < height - i - 1; ++j)
            outputFile << " ";
        
        for (int k = 0; k < 2 * i + 1; ++k)
            outputFile << "*";
        
        outputFile << std::endl;
    }

    // Print the trunk
    int trunkWidth = height / 3;
    int trunkHeight = height / 3;
    for (int i = 0; i < trunkHeight; ++i)
	{
        for (int j = 0; j < height - trunkWidth / 2; ++j)
            outputFile << " ";
        
        for (int k = 0; k < trunkWidth; ++k)
            outputFile << "|";
        
        outputFile << std::endl;
    }
}

//FORCED member functions________________________________________________
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		printMessage(std::cout, "Error: Form not signed!", RED);
	else if ((executor.getGrade() <= this->getReqGradeToExe()))
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (file.is_open())
		{
			printTree(file, 12);
			file.close();
		}
	}
	else
		throw AForm::GradeTooLowException();
}

//getters________________________________________________________________
std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}



