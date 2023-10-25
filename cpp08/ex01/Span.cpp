
# include "Span.hpp"

Span::Span (void){}

Span::Span (const Span& src)
{
    std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span& Span::operator = (const Span& rhs)
{
    std::cout << "Span copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	_numbers = rhs._numbers;
	_capacity = rhs._capacity;
	return *this;
}

Span::~Span()
{
}


Span::Span(unsigned int N): _capacity(N)
{	
}




void Span::addNumber(int num)
{
	if (_numbers.size() == _capacity)
		throw std::out_of_range("(addNumber) Cant add value to Span, max Span size reached!");
	_numbers.insert(num);
}

size_t Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error("(longestSpan) At least 2 values in Span needed for this operation");
	std::multiset<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
	std::multiset<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
	// if (static_cast<size_t>(*max_it + abs(*min_it)) > std::numeric_limits<int>::max())
		// throw std::overflow_error("(longestSpan) Distance over max int, therefore overflowed");
	
	// if (*max_it > 0 && *min_it < 0)
		// return (*max_it - *min_it);
	// else
	return (static_cast<size_t>(*max_it) - static_cast<size_t>(*min_it));
}

size_t Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error("(shortestSpan) At least 2 values in Span needed for this operation");
	
	long shortest_span = std::numeric_limits<long>::max();	
	

	// for (std::multiset<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
	// {
		// for (std::multiset<int>::const_iterator it2 = it + 1; it2 != _numbers.end(); it2++)
		// {
			// shortest_span = std::min(shortest_span, 
			// std::abs(static_cast<long>(*it) - static_cast<long>(*it2)));
			// if (shortest_span == 0)
				// return (0);
		// }
	// }
	return (static_cast<size_t>(shortest_span));
}

void Span::printSpan() const
{
	printContainer(_numbers);
}
