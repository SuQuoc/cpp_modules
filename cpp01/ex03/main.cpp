
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon clubb = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(clubb);
        jim.attack();
        clubb.setType("some other type of club");
        jim.attack();
    }
    //{
    //    HumanA zoro("Zoro");
//
//
    //    HumanB usopp("Usopp");
    //    usopp.attack();
    //    Weapon rifle = Weapon("rifle");
    //    usopp.setWeapon(rifle);
    //    usopp.attack();
    //}
    return 0;
}