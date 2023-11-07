
# pragma once

#include <iostream>

class Fixed
{
	int _rawBits;
	static const int _fractBits; // = 8

	public:
		Fixed(void);
        ~Fixed(void);
		
		//copy constructor
		Fixed (const Fixed& copy); 
		
		//copy assignment operator
		//object is already constructed, we are just
		//makeing a copy later (eg. myFixedNumber2 = myFixedNumber1)
		Fixed& operator = (const Fixed& copy); 

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};