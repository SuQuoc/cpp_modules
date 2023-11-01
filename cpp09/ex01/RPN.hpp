
# pragma once

# include <iostream>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <fstream>
# include <string>
# include <stack>


/* "1 2 * 2 / 2 * 2 4 - +"

top 2 of the stack are always the operands
2nd operand is the top
1st operand is the top-1

minus operator - 
3
4
=


-+
4
2
2
= 0
 */

class RPN
{
private:
	std::stack<double> _numbers;
	void calcSimple(char opr);

public:
	RPN();
	~RPN();
	RPN(const RPN& src);
	RPN& operator=(const RPN& rhs);

	double calcPolNotation(std::string& equation);
};
