
# include "Array.hpp"


//utils for ________________________________________
void printMessage(std::ostream& output, const std::string& msg, const std::string& color)
{
	output << color << msg << RESET << std::endl;
}


template<typename T>
Array<T>::Array(): _size(1)
{
	printMessage(std::cout, "Default constructor", GREEN);
	data = new T();
	data[0] = T();

}

template<typename T>
Array<T>::~Array()
{
	printMessage(std::cout, "Destructor", YELLOW);
	delete[] data;
}

template<typename T>
Array<T>::Array(const Array& src)
{
	printMessage(std::cout, "Copy constructor", BLUE);
	this->data = new T[src.size()]();	
	*this = src;
}


template<typename T>
Array<T>& Array<T>::operator = (const Array& rhs)
{
	printMessage(std::cout, "Copy assignment operator", BLUE);
	if (this == &rhs)
		return *this;
	this->_size = rhs.size();	
	for (int i = 0; i < this->_size; i++)
		this->data[i] = rhs.data[i];
	return *this; 
}


template<typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	printMessage(std::cout, "Parametric constructor", GREEN);
	this->data = new T[n]();
}

template<typename T>
int Array<T>::size() const
{
	return this->_size;
}


template<typename T>
T& Array<T>::operator [] (int index)
{
	if (index < 0 || index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}


template<typename T>
void Array<T>::print() const
{
	print_arr(data, _size);
}

template<typename T>
void Array<T>::setAtTo(int index, const T& value)
{
	if (index < 0 || index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	this->data[index] = value; 
}

template<typename T>
void Array<T>::setAllTo(const T& value)
{
	for (int i = 0; i < this->size(); i++)
		this->data[i] = value;
}
