
# pragma once

#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator>  

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

template <typename T>
void printContainer(T& container)
{
	typename T::const_iterator last = container.end();
	last--;
	std::cout << "Your container = {";
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++) 
	{
        std::cout << *it;
		if (it != last)
			std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}



template <typename T>
typename T::iterator easyfind(T& container, const int search) 
{
	
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), search);
	if (it == container.end())
		throw std::out_of_range("easyfind: couldnt find value");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, const int search) 
{
	
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), search);
	if (it == container.end())
		throw std::out_of_range("easyfind: couldnt find value");
    return it;
}


template <typename T, typename S>
void containerTest(T& container, S startValue)
{
	try
	{
		const S fail = startValue * 6;
		container.push_back(startValue);
    	container.push_back(startValue * 2);
    	container.push_back(startValue * 3);
    	container.push_back(startValue * 4);
    	container.push_back(startValue * 5);
		const T constContainer = container;

		printContainer(container);
		printContainer(constContainer);

		std::cout << "Testing easyfind, searching for " << startValue << ": " << *easyfind(container, startValue) << std::endl;
		std::cout << "Testing easyfind, searching for " << startValue * 3 << ": " << *easyfind(constContainer, startValue * 3) << std::endl;
		std::cout << "Testing easyfind, searching for " << fail << ": " << *easyfind(container, fail) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}
