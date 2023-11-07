#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

//tought that leaving the def-con out or putting it in private will cause compile errors 
//since the main does 
//Weapon club = Weapon("katana")
//instead of
//Weapon("katana")

class Weapon
{
    private:
        std::string _type;
        Weapon(void);

    public:
        Weapon(std::string w_name);

        void setType(std::string type);

        const std::string& getType(void);
};

#endif
