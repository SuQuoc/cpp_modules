
# pragma once

# include <stack>
# include <iterator>
# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>



template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T>
{
public:
		typedef typename container::iterator iterator;
private:

public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& src);
		MutantStack& operator=(const MutantStack& src);

		iterator begin();
		iterator end();

};

template <typename T, typename container>
MutantStack<T, container>::MutantStack(const MutantStack& src)
{
	*this = src;
}


template <typename T, typename container>
MutantStack<T, container>& MutantStack<T, container>::operator=(const MutantStack& src)
{
	std::stack<T, container>::operator=(src); 
	return (*this);
}


template <typename T, typename container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin()
{
	return this->c.begin();
}

template <typename T, typename container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end()
{
	return this->c.end();
}
