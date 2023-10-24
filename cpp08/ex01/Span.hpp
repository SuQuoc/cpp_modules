
# pragma once 

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <limits>

# include "Tests.hpp"

class Span
{
private:
	Span();
	std::vector<int> _numbers;
	unsigned int _capacity;

public:
	Span(unsigned int N);
	~Span();
	Span(const Span& src);
	Span& operator = (const Span& src);

	void addNumber(int num);
	void addManyNumbers(size_t amount, size_t value);
	void printSpan() const ;
	int shortestSpan() const ;
	int longestSpan() const;
};



