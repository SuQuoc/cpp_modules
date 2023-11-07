
#include "Harl.hpp"

//func_arr{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error},
Harl::Harl(void)
{    
    this->level_arr[0] = "debug";
    this->level_arr[1] = "info";
    this->level_arr[2] = "warning";
    this->level_arr[3] = "error";
    
    this->func_arr[0] = &Harl::debug;
    this->func_arr[1] = &Harl::info;
    this->func_arr[2] = &Harl::warning;
    this->func_arr[3] = &Harl::error;
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void Harl::debug( void )
{
    std::cout << "Im debuging cuz i didnt thought everything through before! Thats normal buddy keep calm and debug" << std::endl;
}

void Harl::info( void )
{
    std::cout << "Need more information? RTFM, ask a peer or the internet" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "Warning you did smth i didnt expect!" << std::endl;

}

void Harl::error( void )
{
    std::cout << "Error why do u break stuff all the time?!?!?" << std::endl;
}

void Harl::complain( std::string level )
{
    for (size_t i = 0; i < 4; i++)
    {
        if (level == this->level_arr[i])
            (this->*func_arr[i])();
    }
}
