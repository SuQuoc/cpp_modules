
#include "Zombie.hpp"

int main()
{
    Zombie z1("Ryuma the samurai");
    z1.announce();
    
    int count = 10;
    Zombie* p_horde = zombieHorde(count, "ben10");
    for (int i = 0; i < count; i++)
    {
        p_horde[i].announce();
    }
    delete [] p_horde;

    /*  Zombie arr[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = Zombie("test");
    }
    for (int i = 0; i < 4; i++)
    {
        arr[i].announce();
    } */

    return (0);
}