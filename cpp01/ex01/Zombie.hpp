#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie(void);
        Zombie(std::string z_name);
        ~Zombie(void);
        void announce(void);
    private:
        std::string name;
};

//void randomChump( std::string name );
//Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );


#endif