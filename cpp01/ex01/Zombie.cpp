
#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "constructing a Zombie "<< std::endl;
}

Zombie::Zombie(std::string z_name) : name(z_name)
{
    std::cout << "constructing a Zombie named " << this->name << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "destructing: " << name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

