
# pragma once
# include <string>
# include <sstream>
# include <iostream>
# include "Data.hpp"


typedef unsigned int* uintptr_t;

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& src);
	Serializer& operator = (const Serializer& rhs);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);	
};
