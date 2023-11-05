
#pragma once

#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <deque>
#include <iomanip>
#include <iostream>



# define DECIMAL_BASE 10
# define K 20

template <typename T>
void printContainer(T& container)
{
	typename T::const_iterator last = container.end();
	last--;

	std::cout << " ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++) 
	{
        std::cout << *it;
		if (it != last)
			std::cout << " ";
    }
    std::cout << std::endl;
}

class PmergeMe
{
private:
	std::vector<size_t> _vec;
	std::deque<size_t> _deq;

	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& rhs);

	void loadData_Vec(char **argv);
	void insertion_Vec(int start, int end);
	void merge_Vec(int start, int pivot, int end);
	void mergeInsertSort_Vec(int start, int end);

	void loadData_Deq(char **argv);
	void insertion_Deq(int start, int end);
	void merge_Deq(int start, int pivot, int end);
	void mergeInsertSort_Deq(int start, int end);

public:
	PmergeMe();
	~PmergeMe();
	
	void sort_Vec(char **argv);
	void sort_Deq(char **argv);
	
	void printVec() const;
	void printDeq() const;
	
	size_t getVecSize() const;
	size_t getDeqSize() const;
};
