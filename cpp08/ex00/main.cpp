
# include <algorithm>
# include <iostream>
# include <vector>
# include <list>

# include "easyfind.hpp"




void testFrameWork(void (*funcPTR)())
{
	if (funcPTR == NULL)
		std::cerr << RED << "Error: Invalid pointer" << std::endl << RESET;
	try
	{
		funcPTR();
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}




void vectorTestString()
{
	int n = 10;
	std::vector<std::string> Vect;
	Vect.push_back("a");
    Vect.push_back("ab");
    Vect.push_back("abc");
    Vect.push_back("abcd");
    Vect.push_back("abcde");
	const std::vector<std::string> constVector = Vect;
	
	printContainer(Vect);
	// printContainer(constVector);

	std::cout << "Testing easyfind, searching for " << n << ": " << *easyfind(Vect, n) << std::endl;
	// std::cout << "Testing easyfind, searching for " << n << ": " << *easyfind(constVector, n) << std::endl;
	// std::cout << "Testing easyfind, searching for " << n << ": " << *easyfind(Vect, n) << std::endl;
}

int main()
{	

	std::vector<int> 	iVector;
	std::vector<float>	fVector;
	std::list<float>	fList;
	std::list<double> 	dList;

	containerTest<std::vector<int>, int>(iVector, 50);
	containerTest<std::vector<float>, float>(fVector, 10.0f);
	containerTest<std::list<float>, float>(fList, 1.0f);
	containerTest<std::list<double>, double>(dList, 1.0);

	vectorTestString();
}
