
# pragma once 

# include <iostream>
# include <sstream>
# include <vector>
# include <set>
# include <algorithm>
# include <limits>

# include "Tests.hpp"

class Span
{
private:
	Span();
	std::multiset<int> _numbers;
	unsigned int _capacity;

public:
	Span(unsigned int N);
	~Span();
	Span(const Span& src);
	Span& operator = (const Span& src);

	void addNumber(int num);
	template<typename T>
	void addManyNumbers(T first, T last);
	void printSpan() const ;
	size_t shortestSpan() const ;
	size_t longestSpan() const;
};


template<typename T>
void Span::addManyNumbers(T first, T last)
{
	size_t amount = std::distance(first, last);
	std::cout << amount << std::endl;
	if (amount > _capacity - _numbers.size())
		throw std::out_of_range("(addManyNumbers) Cant add values to Span, not enough space!");
	_numbers.insert(first, last);
	int a = last - first;

	std::cout << "HALLO" << a << std::endl;
}




