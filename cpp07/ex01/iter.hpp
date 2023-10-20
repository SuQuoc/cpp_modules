
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
void times2byAdding(Type& number)
{
	number = number + number;
}

/* I dont like this version since u have to explicitly specifiy the type <> in order for it to work.
Hmm more save? -> maybe not so bad? */
template<typename Type>
void iter(Type *arr, size_t len, void (*func)(Type&))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template<typename Type>
void iter(Type *arr, size_t len, void (*func)(const Type&))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}


/* I dont like this version either since u can pass anything as F not only function pointers
	+ u also have to specify the type with <>
 */
// template<typename Type, typename F>
// void iter(Type *arr, size_t len, F func)
// {
	// for (size_t i = 0; i < len; i++)
		// func(arr[i]);
// }
