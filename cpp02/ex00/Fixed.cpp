
#include "Fixed.hpp"

Fixed::Fixed(void)
: _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed (const Fixed& copy)
: _rawBits(copy._rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Fixed& Fixed::operator = (const Fixed &copy)
{
    std::cout << "Copy assignmnent operator called" << std::endl;
    if (&copy == this)
    {
        return (*this);
    }
    this->_rawBits = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
