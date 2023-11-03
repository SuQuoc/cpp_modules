
# include "PmergeMe.hpp"

typedef std::chrono::high_resolution_clock::time_point time_point_t;
typedef std::chrono::microseconds duration_t;


void printDuration(const time_point_t& start, size_t n_elements, const std::string& container)
{
	time_point_t end = std::chrono::high_resolution_clock::now();
	duration_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time to process a range of " 
				<< n_elements << " elements with std::" << container << " : "
				<< duration.count() << " us" << std::endl;
}


int main(int argc, char **argv)
{
	if (argc == 1)
		return 1;
	try 
	{
		std::cout << "Before:";
		for (int i = 1; argv[i] != nullptr; ++i)
			std::cout << " " << argv[i];
		std::cout << std::endl;

		PmergeMe test;
		test.sort_Vec(argv);
		std::cout << "After: ";
		test.printVec();

		// PmergeMe p1;
		// time_point_t start = std::chrono::high_resolution_clock::now();
		// p1.sort_Vec(argv);
		// printDuration(start, p1.getVecSize(), "vector");
// 
		// PmergeMe p2;
		// start = std::chrono::high_resolution_clock::now();
		// p2.sort_Deq(argv);
		// printDuration(start, p2.getDeqSize(), "deque");
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	PmergeMe p1;
	time_point_t start = std::chrono::high_resolution_clock::now();
	p1.sort_Vec(argv);
	printDuration(start, p1.getVecSize(), "vector");

	PmergeMe p2;
	start = std::chrono::high_resolution_clock::now();
	p2.sort_Deq(argv);
	printDuration(start, p2.getDeqSize(), "deque");
	return 0;
}
