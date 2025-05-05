#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &myWeapon) :name(name), myWeapon(myWeapon)
{
    ;
}

HumanA::~HumanA()
{
    ;
}

void HumanA::attack()
{
    std::cout << name << " attacks with his " << myWeapon.getType() << std::endl;
}
