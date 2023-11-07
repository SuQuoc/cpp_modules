
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
		Fixed& operator = (const Fixed& copy);
		//overloading operators
		bool operator > (const Fixed& rhs) const;
		bool operator < (const Fixed& rhs) const;
		bool operator >= (const Fixed& rhs) const;
		bool operator <= (const Fixed& rhs) const;
		bool operator == (const Fixed& rhs) const;
		bool operator != (const Fixed& rhs) const;

		//arithmetic operators
		Fixed operator + (const Fixed& rhs) const;
		Fixed operator - (const Fixed& rhs) const;
		Fixed operator * (const Fixed& rhs) const;
		Fixed operator / (const Fixed& rhs) const;
		
		// Overloading the prefix operator
    	Fixed& operator++();
    	Fixed& operator--();
		
		// Overloading the postfix operator
    	Fixed operator ++ (int);
    	Fixed operator -- (int);
		
		// Overloading min
		static Fixed& max(Fixed& f1, Fixed&f2);
		static Fixed& min(Fixed& f1, Fixed&f2);
		
		// Overloading max
		static Fixed& max(const Fixed& f1, const Fixed&f2);
		static Fixed& min(const Fixed& f1, const Fixed&f2);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};