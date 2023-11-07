
#include "Fixed.hpp"

//defining static members
const int Fixed::_fractBits = 8;

//CONSTRUCTORS
Fixed::Fixed(void)
: _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    if (number > 8388607 || number < -8388608)
    {
        std::cout << "The integer is out of range of the fixed point representation with 32 bits" << std::endl;
        std::cout << "The number will not match your input due to overflow" << std::endl;        
    }
    this->_rawBits = number << _fractBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    int max_int_fract_bits = (1 << Fixed::_fractBits) - 1;
    
    float max_fraction = max_int_fract_bits / (1 << Fixed::_fractBits);
    if (number > 8388607 + max_fraction || number < -8388608 + max_fraction)
    {
        std::cout << "The integer is out of range of the fixed point representation with 32 bits" << std::endl;
        std::cout << "The number will not match your input due to overflow" << std::endl;        
    }
    int fixed_p_one = 1 << _fractBits;
    int intPart = (int)number;
    float fractPart = number - intPart;
    
    // convert the integer part to fixed point
    this->_rawBits = intPart << _fractBits;
    this->_rawBits += roundf(fixed_p_one * fractPart);
}

//DESTRUCTOR
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

//COPY CONSTRUCTOR
//:  _rawBits(copy._rawBits) would be also a solution instead of calling the = operator
Fixed::Fixed (const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

//COPY ASSIGNMENT OPERATOR
Fixed& Fixed::operator = (const Fixed &rhs)
{
    std::cout << "Copy assignmnent operator called" << std::endl;
    if (this == &rhs)
    {
        return (*this);
    }
    this->_rawBits = rhs._rawBits;
    return (*this);
}


//MEMBER FUNCTIONS
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
    std::cout << "setRawBits member function called" << std::endl;
    return ;
}

float Fixed::toFloat( void ) const
{
    float fl_representation = float(this->_rawBits) / float(1 << Fixed::_fractBits);
    return fl_representation;
}

int Fixed::toInt( void ) const
{
    int integer = this->_rawBits >> Fixed::_fractBits;
    return integer;
}