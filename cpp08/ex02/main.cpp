
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
	LINE;
}

void iteratorFunctionality()
{
	std::vector<std::string> words;
	words.push_back("Push");
	words.push_back("Pop");
	words.push_back("Test");
	words.push_back("some");
	words.push_back("random");
	words.push_back("words");
	
	MutantStack<std::string> fakerA;

	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
		fakerA.push(*it);
	MutantStack<std::string>::iterator it = fakerA.begin();
	// MutantStack<std::string>::const_iterator it = fakerA.begin();
	it = it + 2;
	*it = "Changed smth in the middle!";
	for (it = fakerA.begin(); it != fakerA.end(); it++)
		std::cout << "Mutantstack: " << *it << std::endl;
}


void subject()
{
	MutantStack<int, std::vector<int> > mstack;
	// MutantStack<int> mstack;
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
	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int, std::vector<int> > s(mstack);
}


void subjectButConst()
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
	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void subjectButString()
{
	MutantStack<std::string> mstack;
	mstack.push("a");
	mstack.push("b");
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push("c");
	mstack.push("d");
	mstack.push("e");
	//[...]
	mstack.push("f");
	MutantStack<std::string>::const_iterator it = mstack.begin();
	MutantStack<std::string>::const_iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<std::string> s(mstack);
}

// here it is important to note that for constructing an iterator 
// it is neccesarry to pass in the correct type if MutantStack was declared with smth other than std::deque
void innerContainerTest()
{
	MutantStack<int, std::vector<int> > mstack;
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
	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int, std::vector<int> > s(mstack);
}


void subjectButList()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char choice = argv[1][0];

	switch (choice)
	{
		case 's':
			testFrameWork(subject);
			break;
		case 'l':
			testFrameWork(subjectButList);
			break;
		case 'c':
			testFrameWork(subjectButConst);
			break;
		case 'm':
			testFrameWork(memberFunctions);
			break;
		case 'i':
			testFrameWork(innerContainerTest);
			break;
		case 'f':
			testFrameWork(iteratorFunctionality);
			break;
		case '?':
			subjectButString();
		default :
			std::cout << "No test available." << std::endl;
	}
}
