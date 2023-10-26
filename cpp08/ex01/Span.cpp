
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



//member functions____________________________________________________
void Span::addNumber(int num)
{
	if (_numbers.size() == _capacity)
		throw std::out_of_range("(addNumber) Cant add value to Span, max Span size reached!");
	_numbers.push_back(num);
}

size_t Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error("(longestSpan) At least 2 values in Span needed for this operation");
	
	std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
	return (static_cast<size_t>(*max_it) - static_cast<size_t>(*min_it));
}

size_t Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::length_error("(shortestSpan) At least 2 values in Span needed for this operation");
	
	long shortest_span = std::numeric_limits<long>::max();	
	

	std::sort(_numbers.begin(), _numbers.end());
	for (std::vector<int>::const_iterator it = _numbers.begin(); it + 1 != _numbers.end(); it++)
	{
		shortest_span = std::min(shortest_span, std::abs(static_cast<long>(*it) - (*(it + 1))));
		if (shortest_span == 0)
			return (0);
	}
	return (static_cast<size_t>(shortest_span));
}

void Span::printSpan() const
{
	printContainer(_numbers);
}
