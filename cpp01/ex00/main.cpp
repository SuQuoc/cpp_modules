
#include "Zombie.hpp"

int main()
{
    Zombie z1("Ryuma the samurai");
    z1.announce();

    //Zombie z2;
    //z2.announce();

    randomChump("Sanji the Penguin");
    
    Zombie *ptr = newZombie("Lola the boar");
    (*ptr).announce();
    delete ptr;
    return (0);
}