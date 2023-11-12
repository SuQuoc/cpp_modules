#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie(std::string z_name);
        ~Zombie(void);
        void announce(void);
    private:
        Zombie(void);
        std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif