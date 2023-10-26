
# pragma once

# include <stack>
# include <iterator>
# include <iostream>
# include <algorithm>


class StackIterator;

template <typename T>
class MutantStack
{
private:
	size_t _stackSize;
	T _fakeStack[];
	class Iterator
	{
		private:
			size_t _n = -1; //forbidden?
		public:
			Iterator();
			~Iterator();
			Iterator(const Iterator& src) = delete;
			Iterator& operator = (const Iterator& src) = delete;

			bool hasNext() const ;
			T next(); //eventuell T* 
	};

	StackIterator _iterator;
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack& operator = (const MutantStack& src);

	T iterator();
};


template <typename T>
MutantStack<T>::Iterator::Iterator(): _n(_i) {};


template <typename T>
bool MutantStack<T>::Iterator::hasNext() const 
{
	return (_n >= 0);
}

template <typename T>
T MutantStack<T>::Iterator::next()
{
	if (!this->hasNext())
		throw std::range_error("(Iterator) No next member");
	_n--;
	return (_fakeStack[_n + 1])
}

template <typename T>

T MutantStack<T>::iterator()
{
	new MutantStack::Iterator(); 
}