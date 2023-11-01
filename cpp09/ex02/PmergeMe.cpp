
# include "PmergeMe.hpp"


// void PmergeMe::sort_Vec()
// {
// 
// }


PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}


/* 
{
	std::vector<size_t>::const_iterator last = _vec.end();
	last--;
	std::cout << "After";
    for (std::vector<size_t>::const_iterator it = _vec.begin(); it != _vec.end(); it++) 
        std::cout << " " << *it;
    std::cout << std::endl;
}
*/

void PmergeMe::loadData_Vec(char **argv)
{
	if (argv == nullptr || argv[0] == nullptr)
		return ; //throw

	char* end = nullptr;

	for (int i = 1; argv[i] != nullptr; ++i) 
	{
	    _vec.push_back(strtoul(argv[i], &end, 10));
	}
}


void PmergeMe::sort_Vec(char **argv)
{

	time_point_t start = std::chrono::high_resolution_clock::now();
	loadData_Vec(argv);
	combinedSort_Vec();

	time_point_t end = std::chrono::high_resolution_clock::now();
	duration_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	//after finishing sort
    std::cout << "Time to process a range of " 
				<< _vec.size() << "elements with std::vector : "
				<< duration.count() << " us" << std::endl;	
}