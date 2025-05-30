#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("A");
    ClapTrap b("B");

    // a.setHitPoints(10);
    a.setAttackDamage(2);
    std::cout << a.getHitPoints() << std::endl;
    std::cout << b.getHitPoints() << std::endl;
    a.attack(b.getName());
    std::cout << a.getEnergyPoints() << std::endl;
}
