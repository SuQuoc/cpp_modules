
# pragma once

# include <stack>
# include <iterator>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

template <typename T>
class MutantStack: public std::stack<T>
{
public:

	typedef typename std::deque<T>::iterator 		iterator;
	typedef typename std::deque<T>::const_iterator 	const_iterator;

	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{
	*this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
	std::stack<T, std::deque<T> >::operator=(src);
	return (*this);
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}


template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}
