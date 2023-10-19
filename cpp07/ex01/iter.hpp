
# pragma once
# include <string>
# include <iostream>
# include <sstream>

template<typename Type>
void print_arr(const Type *arr, int len)
{
	std::ostringstream out;
	out << "your arr = {" ;
	for (int i = 0; i < len; i++)
	{
		out << arr[i];
		if (i != len - 1)
		 	out << ", ";
	}
	out << "}" << std::endl;
	std::cout << out.str();
}

template<typename Type>
void print_arr2(const Type &arr, int len)
{
	std::ostringstream out;
	out << "your arr = {" ;
	for (int i = 0; i < len; i++)
	{
		out << arr[i];
		if (i != len - 1)
		 	out << ", ";
	}
	out << "}" << std::endl;
	std::cout << out.str();
}


template<typename Type>
void times2(Type& number)
{
	number = number * 2;
}

template<typename Type>
void iter(Type *arr, int len, void (*func)(Type&))
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

