
# pragma once

# include <stack>
# include <iterator>
# include <iostream>
# include <vector>
# include <algorithm>


class Iterator;


template <typename T>
class MutantStack //: public Iterable<T>
{
private:
	size_t _stackSize;
	std::vector<T> _fakeStack;
	// T _fakeStack[];
	
	Iterator<T> _iterator;
public:
	typedef T ValueType; //might be forbidden
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);

	T iterator();
	void push(T topElement);
	void pop();
	Iterator<T> begin();
	Iterator<T> end();

	T& top() const ;
	size_t size() const;

	class Iterator
	{
		public:
			typedef typename MutantStack::ValueType ValueType;
			typedef ValueType* PointerType;
			typedef ValueType& RefType;

		private:
			size_t _n;
			PointerType mPTR;
		
			
			Iterator();
			Iterator(PointerType ptr);
			~Iterator();
			Iterator(const Iterator& src);
			Iterator& operator = (const Iterator& src);

			bool hasNext() const ;
			T next(); //eventuell T* 
	};
};

// MutantStack functions_________________________________________________________
template <typename T>
MutantStack<T>::MutantStack(): _stackSize(0)
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{

}

// template <typename T>
// MutantStack& MutantStack<T>::operator=(const MutantStack& src)
// {
	// if (this == &src)
		// return *this;
	// 
	// 
	// return *this
// }




template <typename T>
void MutantStack<T>::push(T topElement)
{
	_fakeStack.insert(_fakeStack.begin(), topElement);
	_stackSize++; //or use vector.size() probably safer
}

template <typename T>
void MutantStack<T>::pop()
{
	_fakeStack.erase(_fakeStack.begin());
	_stackSize--; //or use vector.size() probably safer
}

template <typename T>
T& MutantStack<T>::top() const 
{
	return _fakeStack[0];
}


template <typename T>
size_t MutantStack<T>::size() const 
{
	return _size;
}


template <typename T>
Iterator MutantStack<T>::begin()
{
	return Iterator(_fakeStack.begin());
}


template <typename T>
Iterator MutantStack<T>::end()
{
	return Iterator(_fakeStack.end());
}




// Iterator Canonical Form_________________________________________________________
template <typename T>
MutantStack<T>::Iterator::Iterator(): (_stackSize) {};

template <typename T>
MutantStack<T>::Iterator::~Iterator(): _n(_stackSize) {};



template <typename T>
MutantStack<T>::Iterator::Iterator(PointerType ptr): _mPTR(ptr) {};
// Iterator functions_________________________________________________________






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

//because its private i give the user a way to access the iterator
template <typename T>
T MutantStack<T>::iterator()
{
	new MutantStack::Iterator(); 
}