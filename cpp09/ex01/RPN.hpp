
# pragma once

# include <iostream>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <fstream>
# include <string>
# include <stack>

class RPN
{
private:
	std::stack<double> _numbers;
	RPN(const RPN& src);
	RPN& operator=(const RPN& rhs);
	void calcSimple(char opr);

public:
	RPN();
	~RPN();

	double calcPolNotation(std::string& equation);
};
