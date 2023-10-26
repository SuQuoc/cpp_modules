
// # include "MutantStack.hpp"
# include <stack>
# include <iterator>
# include <iostream>
# include <algorithm>
# include <vector>

# include "helper.hpp"



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

// template<typename T>
// void pushLoop(T container, std::string func)
// {
	// 
	// for (T::iterator it = container.begin(); it != container.end(); it++)
	// {
		// if (func == "pop")
			// func(arr[i]);
	// }			
// }

void memberFunctions()
{
	std::vector<std::string> words;
	words.push_back("Push");
	words.push_back("Pop");
	words.push_back("Test");
	words.push_back("some");
	words.push_back("random");
	words.push_back("words");
	
	std::stack<std::string> stackA;
	// MutantStack<std::string> fakerA;

	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	{
		stackA.push(*it);
		//fakeA.push(*it);
		std::cout << "Top: " << stackA.top() << std::endl;
	}
	LINE;
	std::cout << "Size stack: " << stackA.size() << std::endl;
	// std::cout << "Size faker: " << fakerA.size() << std::endl;
	LINE;
	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	{
		std::cout << "Top: " << stackA.top() << std::endl; //segv instead of throwing exception??
		stackA.pop();
		//fakeA.pop();
	}
	LINE;
	std::cout << "Size stack: " << stackA.size() << std::endl;
	// std::cout << "Size faker: " << fakerA.size() << std::endl;
}



int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char choice = argv[1][0];
	switch (choice)
	{
		case 'm':
			testFrameWork(memberFunctions);
			break;
		default :
			std::cout << "No test available." << std::endl;
	}
}
