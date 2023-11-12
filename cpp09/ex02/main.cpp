
#include "PmergeMe.hpp"
#include <sys/time.h>

void printDuration(clock_t start, size_t n_elements, const std::string& container)
{
	clock_t end = clock();
	long elapsed = end - start;
    double elapsed_time = (double)elapsed / CLOCKS_PER_SEC * 1e6;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " 
				<< n_elements << " elements with std::" << container << " : "
				<< elapsed_time << " us" << std::endl;
	// resetting (std)outputstream settings 
	std::cout << std::setprecision(6);
	std::cout.unsetf(std::ios::fixed);
}

void printDuration2(timeval start, size_t n_elements, const std::string& container)
{
	timeval end;
    // Code to be timed

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long elapsed = seconds * 1000000 + microseconds;

	std::cout << "Time to process a range of " 
				<< n_elements << " elements with std::" << container << " : "
				<< std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;
	//resetting (std)outputstream settings 
	std::cout << std::setprecision(6);
	std::cout.unsetf(std::ios::fixed);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return 1;
	try 
	{
		std::cout << "Before:";
		for (int i = 1; argv[i] != NULL; ++i)
			std::cout << " " << argv[i];
		std::cout << std::endl;

		PmergeMe test;
		test.sort_Vec(argv);
		std::cout << "After: ";
		test.printVec();
		test.checkSort();
	// 	PmergeMe p1;
	// 	clock_t start = clock();
	// 	p1.sort_Vec(argv);
	// 	printDuration(start, p1.getVecSize(), "vector");
// 	
// 	
	// 	PmergeMe p2;
	// 	start = clock();
	// 	p2.sort_Deq(argv);
	// 	printDuration(start, p2.getDeqSize(), "deque");

	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	/* PmergeMe p1;
	clock_t start = clock();
	p1.sort_Vec(argv);
	printDuration(start, p1.getVecSize(), "vector");

	PmergeMe p2;
	start = clock();
	p2.sort_Deq(argv);
	printDuration(start, p2.getDeqSize(), "deque"); */
	return 0;
}
