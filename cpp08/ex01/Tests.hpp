
# pragma once

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <limits>

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

void testFrameWork(void (*funcPTR)());
void rangeTest(void);
void sizeZero_One_Two(void);
void addManyNum(void);
void over10K(void);
void negativeValues(void);
