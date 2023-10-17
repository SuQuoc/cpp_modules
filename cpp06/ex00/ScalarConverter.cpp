
#include "ScalarConverter.hpp"


void printConversionsAllImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}


//type detection______________________________________________________________
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
	std::string::iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it++;
    for (; it != str.end(); it++) 
	{        
		if (!std::isdigit(*it))
            return false;
    }
    return true;
}

bool isHumanCharacter(std::string& str) 
{
	if (str.length() == 1 && std::isprint(str.at(0)) && !std::isdigit(str.at(0)))
		return true;
	return false;
}

//.12f and 12.f both valid as the compiler doesnt cry 
bool isFloat(std::string& str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	if (str.at(str.length() - 1) == 'f'
		&& NumOfOcurrences(str, 'f') == 1
		&& NumOfOcurrences(str, '.') <= 1)
	{
		std::string::iterator it = str.begin();
		if (*it == '+' || *it == '-')
			it++;
    	for (; it != (str.end() - 1); it++) 
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
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;
	if (NumOfOcurrences(str, '.') != 1)
		return false;
	
	std::string::iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it++;
    for (; it != str.end(); it++) 
	{        
		if (!std::isdigit(*it) && *it != '.')
            return false;
    }
	return true;
}

void charToOther(int *i, char *c, float *f, double *d, std::string& input)
{
	*c = input.at(0);
	*i = static_cast<int>(*c);
	*f = static_cast<float>(*c);
	*d = static_cast<double>(*c);
}

void checkAndprintChar(char c, double number)
{
	if (number > std::numeric_limits<char>::max() || number < std::numeric_limits<char>::min() || std::isnan(number))
		std::cout << "char: impossible" << std::endl;
	else if (isascii(c) && std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}
void checkAndprintInt(int i, double number)
{
	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min() || std::isnan(number))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}
void checkAndprintFloat(float f, double number)
{
	std::string decimalPart = "";
	if (static_cast<float>(static_cast<int>(f)) == f)
		decimalPart = ".0";
	if ((number > std::numeric_limits<float>::max() || number < -std::numeric_limits<float>::max())
		&& f != +INFINITY && f != -INFINITY && f != NAN)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << decimalPart << "f" << std::endl;
}

void printDouble(double d)
{
	std::string decimalPart = "";
	if (static_cast<double>(static_cast<int>(d)) == d)
		decimalPart = ".0";
	std::cout << "double: " << d << decimalPart << std::endl;
}

void printConversions(char c, int i, float f, double d)
{
	checkAndprintChar(c, d);
	checkAndprintInt(i, d);
	checkAndprintFloat(f, d);
	printDouble(d);
}

//012, 012f, 012.0 anything with 0 at the beginning isnt covered
void ScalarConverter::convert(std::string& input)
{
	int i;
	char c;
	float f;
	double d;
	
	std::istringstream iss(input);
	if (input.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	else if (isHumanCharacter(input))
	{
		c = input.at(0);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		printConversions(c, i, f, d);
	}
	else if (isNumeric(input))
	{
		iss >> i;
		if (iss.fail())
			printConversionsAllImpossible();
		else
		{
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			printConversions(c, i, f, d);
		}
	}
	else if (isFloat(input))
	{
		if (input == "+inff")
			f = +INFINITY;
		else if (input == "-inff")
			f = -INFINITY;
		else if (input == "nanf")
			f = NAN;
		else 
		{
			iss >> f;
			if (iss.fail())
				return printConversionsAllImpossible();
		}
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		printConversions(c, i, f, d);
	}
	else if (isDouble(input))
	{
		if (input == "+inf")
			d = +INFINITY;
		else if (input == "-inf")
			d = -INFINITY;
		else if (input == "nan")
			d = NAN;
		else 
		{
			iss >> d;
			if (iss.fail())
				printConversionsAllImpossible();
		}
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		printConversions(c, i, f, d);
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
}
