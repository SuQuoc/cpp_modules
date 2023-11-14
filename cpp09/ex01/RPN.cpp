
# include "RPN.hpp"

//Constructors_______________________________________________________
RPN::RPN()
{}

RPN::~RPN()
{}


RPN::RPN(const RPN& src)
{
	(void)src;
	return ;
}

RPN& RPN::operator=(const RPN& rhs)
{
	(void)rhs;
	return *this;
}


void RPN::calcSimple(char opr)
{
	double firstOperand;
	double secondOperand;

	secondOperand = _numbers.top();
	_numbers.pop();
	firstOperand = _numbers.top();
	_numbers.pop();
	switch (opr)
	{
		case '+':
			_numbers.push(firstOperand + secondOperand);
			break;
		case '-':
			_numbers.push(firstOperand - secondOperand);
			break;
		case '*':
			_numbers.push(firstOperand * secondOperand);
			break;
		case '/':
			if (secondOperand == 0)
				throw std::invalid_argument("division by zero");
			_numbers.push(firstOperand / secondOperand);
			break;
		default:
			throw std::invalid_argument("invalid operator (should not happen)");
	}
}


/* throws "input in incorrect reverse polish notation" if:
ratio [operators = operands - 1] is not uphold or 
if theres not at least 2 operands in the stack */
double RPN::calcPolNotation(std::string& equation)
{
	if (equation.find_first_not_of("+-*/ 0123456789") != std::string::npos)
		throw std::domain_error("invalid input");
	
	std::string s;
	std::string operators = "+-*/";
	std::string::iterator it_b = equation.begin();
	std::string::iterator it_e = equation.end();

	for (std::string::iterator it = it_b; it != it_e; it++)
	{
		if (isdigit(*it))
		{
			if (it + 1 != it_e && isdigit(*(it + 1)) )
				throw std::domain_error("only numbers between 0 to 9 allowed");
			s = equation.substr(it - it_b, 1);
			_numbers.push(atof(s.c_str()));
		}
		if (operators.find(*it) != std::string::npos)
		{
			if (_numbers.size() < 2)
				throw std::domain_error("input in incorrect reverse polish notation");
			calcSimple(*it);
		}
	}
	if (_numbers.size() != 1) //if the ratio (operators = operands - 1) is not uphold
		throw std::domain_error("input in incorrect reverse polish notation"); 
	double result = _numbers.top();
	_numbers.pop();
	return result;
}
