
#include "ScalarConverter.hpp"



void displayConversions(char c, int i, float f, double d)
{
	std::cout << "char: " << c << std::endl
				<< "int: " << i << std::endl
				<< "float: " << f << std::endl
				<< "double: " << d << std::endl;
}

int NumOfOcurrences(std::string& str, char c)
{    
   	int n_occurence = 0;

    for (size_t pos = str.find(c); pos != std::string::npos; pos = str.find(c, pos))
    {   
        pos++;
		n_occurence++;
    }
	return n_occurence;
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

//.12f and 12.f both valid as the compiler doesnt cry 
bool isFloat(std::string& str)
{
	if (str.at(str.length() - 1) == 'f'
		&& NumOfOcurrences(str, 'f') == 1
		&& NumOfOcurrences(str, '.') <= 1)
	{
		std::string::iterator it;
    	for (it = str.begin(); it != (str.end() - 1); it++) 
		{        
			if (!std::isdigit(*it) && *it != '.')
    	        return false;
    	}
		return true;
	}
	return false;
}

//.12 and 12. both valid as the compiler doesnt cry 
bool isDouble(std::string& str)
{
	if (NumOfOcurrences(str, '.') != 1)
		return false;
	std::string::iterator it;
    for (it = str.begin(); it != str.end(); it++) 
	{        
		if (!std::isdigit(*it) && *it != '.')
            return false;
    }
	return true;
}





void ScalarConverter::convert(std::string& input)
{
	if (isNumeric(input))
		std::cout << "Numeric" << std::endl;
	else if (isHumanCharacter(input))
		std::cout << "Character" << std::endl;
	else if (isFloat(input))
		std::cout << "Float" << std::endl;
	else if (isDouble(input))
		std::cout << "Double" << std::endl;
	else
		std::cout << "Invalid" << std::endl;

}
