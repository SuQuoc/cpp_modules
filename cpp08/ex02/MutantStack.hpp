
# pragma once

# include <stack>
# include <iterator>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container>
{
public:
	typedef typename container::iterator 		iterator;
	typedef typename container::const_iterator 	const_iterator;

	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
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


template <typename T, typename container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::begin() const
{
	return this->c.begin();
}

template <typename T, typename container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::end() const
{
	return this->c.end();
}
