
# pragma once
# include <string>
# include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator = (const ScalarConverter& rhs);

public:
	void static convert(std::string& input);
};