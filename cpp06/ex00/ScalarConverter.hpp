
# pragma once
# include <string>
# include <iostream>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator = (const ScalarConverter& rhs);
	~ScalarConverter();
	
	void static convert(std::string& input);
};