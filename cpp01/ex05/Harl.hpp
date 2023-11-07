
# pragma once

#include <iostream>

class Harl
{
	typedef void(Harl::*mem_function)();
	mem_function func_arr[4];
	std::string level_arr[4];
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	public:
		Harl(void);
        ~Harl(void);

		void complain( std::string level );
};