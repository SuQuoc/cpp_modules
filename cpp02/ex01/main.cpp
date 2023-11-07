
#include "Fixed.hpp"
#include <iostream>


//overload of the insertion («) operator without "friend key word"
//since the fixed_point_number is private i need to call getRawbits()
//if i wanted to add two Fixed Objects i would put the operator overload in the class
//if i wanted to add 2 different Objects i would use the friend keyword but since its not allowed i do this 
std::ostream& operator << (std::ostream& stream, const Fixed& rhs)
{
    stream << rhs.toFloat();
    return (stream);
}

int main( void ) 
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    
    a = Fixed( 1234.4321f );
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
    return 0;
}


//Default constructor called
//Int constructor called
//Float constructor called
//Copy constructor called
//Copy assignment operator called
//Float constructor called
//Copy assignment operator called
//Destructor called

//a is 1234.43
//b is 10
//c is 42.4219
//d is 10
//a is 1234 as integer
//b is 10 as integer
//c is 42 as integer
//d is 10 as integer
//Destructor called
//Destructor called
//Destructor called
//Destructor called
