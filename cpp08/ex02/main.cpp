
# include <stack>
# include <iterator>
# include <iostream>
# include <cstdlib>
# include <string>
# include <algorithm>
# include <vector>
# include <iomanip> // Include the iomanip header for setw

# include "MutantStack.hpp"
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
	MutantStack<std::string> fakerA;

	LINE;
	std::cout << "      " << std::left << std::setw(11) << "Stack";
	std::cout << std::setw(20) << "| MutantStack" << std::endl;
	LINE;
	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	{
		stackA.push(*it);
		fakerA.push(*it);
		std::cout << std::left << std::setw(7) << "Top:" << std::setw(10) << stackA.top();
		std::cout << std::setw(5) << "|" << fakerA.top() << std::endl;
	}
	LINE;
	std::cout << std::left << std::setw(7) << "Size:" << std::setw(10) << stackA.size();
	std::cout << std::setw(5) << "|" <<fakerA.size() << std::endl;
	LINE;
	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	{
		std::cout << std::left << std::setw(7) << "Top:" << std::setw(10) << stackA.top();
		std::cout << std::setw(5) << "|" << fakerA.top() << std::endl;
		stackA.pop();
		fakerA.pop();
	}
	LINE;
	std::cout << std::left << std::setw(7) << "Size:" << std::setw(10) << stackA.size();
	std::cout << std::setw(5) << "|" <<fakerA.size() << std::endl;
}

void subject()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
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
		case 's':
			testFrameWork(subject);
			break;
		default :
			std::cout << "No test available." << std::endl;
	}
}
