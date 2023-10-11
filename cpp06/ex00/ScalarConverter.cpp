
#include "ScalarConverter.hpp"



void displayConversions(char c, int i, float f, double d)
{
	std::cout << "char: " << c << std::endl
				<< "int: " << i << std::endl
				<< "float: " << f << std::endl
				<< "double: " << d << std::endl;
}


bool isNumeric(std::string& str) 
{
	std::string::iterator it; 
    for (it = str.begin(); it != str.end(); it++) 
	{        
		if (!std::isdigit(*it))
            return false;
    }
    return true;
}

bool isHumanCharacter(std::string& str) 
{
	if (str.length() == 1 && std::isprint(str.at(0)))
		return true;
	return false;
}


bool isDouble(std::string& str)
{
	std::string::iterator it; 
    for (it = str.begin(); it != str.end(); it++) 
	{        
		if (!std::isdigit(*it) && *it != '.')
            return false;
    }
	if (NumOfOcurrences(str, '.') != 1)
		return false;
	return true;
}


bool isFloat(std::string& str)
{
	if (isDouble(str) && )
}

int NumOfOcurrences(std::string& str, char c)
{    
    size_t n_occurence = 0;

    for (size_t pos = str.find(c); pos != std::string::npos; pos = str.find(c, pos))
    {   
        pos++;
		n_occurence++;
    }
	return n_occurence;
}

void ScalarConverter::convert(std::string& input)
{
	if (isNumeric(input))
		std::cout << "!!!!!!!!!!!" << std::endl;
	else if (isHumanCharacter(input))
		std::cout << "!!!!!!!!!!!" << std::endl;
}