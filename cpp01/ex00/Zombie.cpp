
#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return;
}

Zombie::Zombie(std::string z_name) : name(z_name)
{
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "destructing: " << this->name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

