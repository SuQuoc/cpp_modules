
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

void Span::addManyNumbers(size_t amount, size_t value)
{
	if (amount > _capacity - _numbers.size())
		throw std::out_of_range("(addManyNumbers) Cant add values to Span, not enough space!");
	// new impl with another data type
	std::vector<int>::iterator pos = _numbers.end();
	_numbers.insert(pos, amount, value);
}


void Span::addNumber(int num)
{
	// std::cout << "Current size: " << _numbers.size() << "Capacity" <<_capacity << std::endl;
	if (_numbers.size() == _capacity)
		throw std::out_of_range("(addNumber) Cant add value to Span, max Span size reached!");
	_numbers.push_back(num);
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error("(longestSpan) At least 2 values in Span needed for this operation");
	std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());

	return (std::abs(*max_it - *min_it));
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error("(shortestSpan) At least 2 values in Span needed for this operation");
	
	int shortest_span = std::numeric_limits<int>::max();

	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		for (std::vector<int>::const_iterator it2 = it + 1; it2 != _numbers.end(); it2++)
			shortest_span = std::min(shortest_span, std::abs(*it - *it2));
	}
	return (shortest_span);
}

void Span::printSpan() const
{
	printContainer(_numbers);
}
