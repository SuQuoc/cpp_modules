
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_myWpon = NULL;
}

HumanB::HumanB(std::string name, Weapon* weapon):
    _name(name),
    _myWpon(weapon)
{
    return ;
}

void HumanB::attack(void)
{
    if (_myWpon != NULL)
        std::cout << this->_name << " attacks with their " << (*this->_myWpon).getType() << std::endl;
    else
        std::cout << "Im a pacifist you moron, peace out" << std::endl;
}

void HumanB::setWeapon(Weapon& type)
{
    this->_myWpon = &type;
}