
# pragma once

# include <iostream>


template< typename Type>
Type max(const Type& x, const Type& y)
{
	return (x > y ? x : y);
}

template< typename Type>
Type min(const Type& x, const Type& y)
{
	return ((x < y) ? x : y);
}



template< typename Type>
void swap(Type& x, Type& y)
{
	Type tmp = x;
	x = y;
	y = tmp;
}
