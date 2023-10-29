
# pragma once 

# include <iostream>
# include <sstream>
# include <vector>
# include <set>
# include <algorithm>
# include <limits>
# include <iterator>

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
	template<typename InputIt>
	void addManyNumbers(InputIt first,InputIt last);

	void printSpan() const ;
	size_t shortestSpan() ;
	size_t longestSpan() const;
};


template<typename InputIt>
void Span::addManyNumbers(InputIt first,InputIt last)
{
	size_t amount = std::distance(first, last);
	if (amount > _capacity - _numbers.size())
		throw std::out_of_range("(addManyNumbers) Cant add values to Span, not enough space!");
	_numbers.insert(_numbers.end(), first, last);
}
