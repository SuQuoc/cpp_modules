
# pragma once

# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>  // For rand() and srand()
# include <ctime>    // For time()

class Base
{
	public:
		virtual ~Base();
};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);
