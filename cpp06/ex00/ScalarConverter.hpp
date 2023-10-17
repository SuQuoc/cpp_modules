
# pragma once
# include <string>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <cmath>

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
