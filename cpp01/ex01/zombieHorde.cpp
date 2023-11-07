
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* ptr = NULL;
    try 
    {
        ptr = new Zombie[N];
        for (int i = 0; i < N; i++)
        {
            ptr[i] = Zombie(name); //i think the constructor is called twice for each zombie
        }
    }
    catch (std::bad_alloc& exc)
    {
        std::cout << "bad_alloc caught: " << exc.what() << std::endl;
    }
    return (ptr);
}