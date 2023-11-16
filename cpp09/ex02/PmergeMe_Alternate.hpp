
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
#include <limits>

# define DECIMAL_BASE 10
# define K 10

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
	typedef std::vector <std::pair<size_t, size_t> > pair_vector;
	typedef std::deque <std::pair<size_t, size_t> > pair_deque;
	
	std::vector<size_t> _vec;
	std::deque<size_t> _deq;
	size_t _last;

	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& rhs);

	size_t getJacobsthalNumber(size_t n) const ;

	void loadData_Vec(char **argv);
	void FJohnsonSortVec();
	void generate_pairsVec(pair_vector& pairs);
	void sort_pairsVec(pair_vector& pairs);
	int binarySearchVec(std::vector<size_t>& arr, size_t num, int left, int right);
	std::vector<int> getB_indicesVec(int numberOfBs);
	
	void loadData_Deq(char **argv);
	void FJohnsonSortDeq(std::deque<size_t>& arr);
	void generate_pairsDeq(pair_deque& pairs, std::deque<size_t>& arr);
	void sort_pairsDeq(pair_deque& pairs);
	int binarySearchDeq(std::deque<size_t>& arr, size_t num, int left, int right);
	std::deque<int> getB_indicesDeq(int numberOfBs);
public:
	PmergeMe();
	~PmergeMe();
	
	void checkSortVec();
	void checkSortDeq();

	void sort_Vec(char **argv);
	void sort_Deq(char **argv);
	
	void printVec() const;
	void printDeq() const;
	
	size_t getVecSize() const;
	size_t getDeqSize() const;
};
