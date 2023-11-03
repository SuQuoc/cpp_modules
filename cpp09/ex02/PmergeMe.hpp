
# pragma once

# include <iostream>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <fstream>
# include <string>
# include <vector>
# include <deque>
# include <list>
# include <chrono>

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

public:
	PmergeMe();
	~PmergeMe();
	void loadData_Vec(char **argv);
	void insertion_Vec(int start, int end);
	void sort_Vec(char **argv);
	void mergeInsertSort_Vec(int start, int end);
	void merge_Vec(int start, int pivot, int end);

	void loadData_Deq(char **argv);
	void insertion_Deq(int start, int end);
	void sort_Deq(char **argv);
	void mergeInsertSort_Deq(int start, int end);
	void merge_Deq(int start, int pivot, int end);

	void printVec() const;
	void printDeq() const;
	
	size_t getVecSize() const;
	size_t getDeqSize() const;
	
	// void loadData_Vec();
	// void mergeInsertionSort_Vec();


};
