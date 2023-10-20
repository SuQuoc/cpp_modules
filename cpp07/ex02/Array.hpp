
# pragma once

# include <string>
# include <iostream>
# include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

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
// template<typename Type>
// void create(const Type *arr, int len)
// {
	// std::ostringstream out;
	// out << "your arr = {" ;
	// for (int i = 0; i < len; i++)
	// {
		// out << arr[i];
		// if (i != len - 1)
		 	// out << ", ";
	// }
	// out << "}" << std::endl;
	// std::cout << out.str();
// }

template<typename T>
class Array
{
private:
	int _size;
	T *data;
public:
	Array();
	~Array();
	Array(const Array& src);
	Array& operator = (const Array& rhs);
	
	Array(unsigned int n);
	T& operator [] (int position);
	int size() const; 

	void print() const;
	void setAllTo(const T&);

};

#include "Array.tpp"

