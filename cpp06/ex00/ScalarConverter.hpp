
# pragma once
# include <string>
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <limits>


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