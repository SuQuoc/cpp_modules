
# pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _rawBits;
		static const int _fractBits;

	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);

		~Fixed(void);
		
		//copy constructor
		Fixed (const Fixed& copy);
		
		//copy assignment operator
		//object is already constructed, we are just
		//makeing a copy later (eg. myFixedNumber2 = myFixedNumber1)
		Fixed& operator = (const Fixed& copy);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};