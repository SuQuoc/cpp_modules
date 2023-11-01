
# pragma once

# include <iostream>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <fstream>
# include <string>
# include <vector>
# include <list>
# include <chrono>


class PmergeMe
{
private:
	typedef std::chrono::high_resolution_clock::time_point time_point_t;
	typedef std::chrono::microseconds duration_t;
	
	std::vector<size_t> _vec;
	std::list<size_t> _list;
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& rhs);

public:
	PmergeMe();
	~PmergeMe();
	void loadData_Vec(char **argv);
	void sort_Vec(char **argv);
	void combinedSort_Vec();
	void mergeSort_Vec();
	void insertionSort_Vec();

	// void loadData_Vec();
	// void mergeInsertionSort_Vec();


};
