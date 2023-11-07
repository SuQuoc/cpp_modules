
#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string w_name) : _type(w_name)
{
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string& Weapon::getType(void)
{
    std::string &ref = this->_type;
    return (ref);
}