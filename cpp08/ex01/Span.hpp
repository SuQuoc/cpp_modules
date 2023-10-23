
# pragma once 

# include <iostream>
# include <sstream>


class Span
{
private:
	Span();
public:
	Span(unsigned int N);
	~Span();
	Span(const Span& src);
	Span& operator = (const Span& src);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
};



