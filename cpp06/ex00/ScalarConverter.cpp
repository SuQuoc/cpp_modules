
#include "ScalarConverter.hpp"

void printFloatsAndDoubles(int i, float f, double d)
{
	std::string decimalPart = "";
	if (f - static_cast<float>(i) == 0)
		decimalPart = ".0";

	int double_precision = std::numeric_limits<double>::digits10;
    int float_precision = std::numeric_limits<float>::digits10;

	std::cout.unsetf ( std::ios::floatfield );
	std::cout.precision(float_precision);
	std::cout << "float: " << f << decimalPart << "f" << std::endl;
	std::cout.precision(double_precision);
	std::cout << "double: " << d << decimalPart << std::endl;
}

void displayConversions(char c, int i, float f, double d)
{
	if (std::isprint(i))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	
	printFloatsAndDoubles(i, f, d);
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
// 012 is weird with compiler returns 10
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

void intToOther(int *i, char *c, float *f, double *d, std::string& input)
{
	*i = atoi(input.c_str());
	*c = static_cast<char>(*i);
	*f = static_cast<float>(*i);
	*d = static_cast<double>(*i);

}

void floatToOther(int *i, char *c, float *f, double *d, std::string& input)
{
	char *end;
	*f = strtof(input.c_str(), &end);
	*i = static_cast<int>(*f);
	*c = static_cast<char>(*f);
	*d = static_cast<double>(*f);
}

void doubleToOther(int *i, char *c, float *f, double *d, std::string& input)
{
	char *end;
	*d = strtod(input.c_str(), &end);
	//*d = 123.43453244;
	std::cout << "FLOAT TO OTHER: " << *d << std::endl;
	*i = static_cast<int>(*d);
	*c = static_cast<char>(*d);
	*f = static_cast<float>(*d);
}

void charToOther(int *i, char *c, float *f, double *d, std::string& input)
{
	*c = input.at(0);
	*i = static_cast<int>(*c);
	*f = static_cast<float>(*c);
	*d = static_cast<double>(*c);
}


//012, 012f, 012.0 anytrhing with 0 at the beginning isnt covered
void ScalarConverter::convert(std::string& input)
{
	int i = 0;
	char c = 0 ;
	float f = 0;
	double d = 0;
   
	if (isNumeric(input))
		intToOther(&i, &c, &f, &d, input); //str
	else if (isHumanCharacter(input))
		charToOther(&i, &c, &f, &d, input);
	else if (isFloat(input))
		floatToOther(&i, &c, &f, &d, input);
	else if (isDouble(input))
		doubleToOther(&i, &c, &f, &d, input);
	else
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	displayConversions(c, i, f, d);
}
