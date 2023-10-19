
# include "Array.hpp"
# include <iostream>

#define LINE    std::cout << "---------------------------" << std::endl;

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

void deepCopyTest()
{
	
	unsigned int n = 5;

	Array<int> arr1(n);
	arr1.print();
	arr1.setAllTo(10);
	arr1[0] = 1;
	arr1.print();
	//print_arr<int>(arr1, n);
	//set numbers and print_arr<int>(arr1, n);
	LINE;

	Array<int> arr2(arr1);
	arr2[0] = 2;
	arr2.print();
	arr1.print();
	LINE;

	Array<int> arr3(n);
	arr3.setAllTo(3);	
	arr3 = arr2;
	arr3[0] = 3;
	
	arr2.print();
	arr3.print();
}

int main (int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string in = argv[1];
	
	// std::string * a = new std::string();
	// std::cout << *a << std::endl;

	if (in == "0")
	{
		testFrameWork(deepCopyTest);
	}
	// else if (in == "1")
		// Array<int> arr();
	// else if (in == "2")
	// {		
		// Array<int> arr(5);
	// }
}
