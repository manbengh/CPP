#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    myWeapon = NULL;
}

HumanB::~HumanB()
{
    ;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    myWeapon = &newWeapon;
}

void HumanB::attack()
{
    if (myWeapon)
        std::cout << name << " attacks with his " << myWeapon->getType() << std::endl;
    else
        std::cout << name << "No weapons to attack with !" << std::endl;

}
