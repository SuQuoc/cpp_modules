
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
	return *this;
}

Span::~Span()
{
}


void Span::addNumber(int num)
{

}

int Span::longestSpan()
{

}

int Span::shortestSpan()
{

}