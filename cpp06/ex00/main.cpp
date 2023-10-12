
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	// double d = 12.;	
	// float f = 12.11f;
	// std::cout << d << std::endl;
	// std::cout << f << std::endl;

	// Implicit conversion
	// double d = 324.234;
	// int i = d;
	std::string input = argv[1];
	ScalarConverter::convert(input);
}