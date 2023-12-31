
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon* _myWpon;
    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon *weapon);
        void attack(void);
        void setWeapon(Weapon& wpon);
};

#endif