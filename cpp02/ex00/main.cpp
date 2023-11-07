
#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    //std::cout << std::endl << "More tests:" << std::endl;
    //a.setRawBits(10.213);
    //b.setRawBits(20);
    //c.setRawBits(30);
    //std::cout << a.getRawBits() << std::endl;
    //std::cout << b.getRawBits() << std::endl;
    //std::cout << c.getRawBits() << std::endl;

    return 0;
}

//$> ./a.out
//Default constructor called
//Copy constructor called
//Copy assignment operator called // <-- This line may be missing depending on your implementation
//getRawBits member function called
//Default constructor called
//Copy assignment operator called
//getRawBits member function called
//getRawBits member function called
//0
//getRawBits member function called
//0
//getRawBits member function called
//0
//Destructor called
//Destructor called
//Destructor called
//$>