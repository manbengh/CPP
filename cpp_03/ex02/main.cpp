#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void printStatus(const ClapTrap& c)
{
    std::cout << "---- " << c.getName() << " ----" << std::endl;
    std::cout << "Hit Points: " << c.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << c.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << c.getAttackDamage() << std::endl;
    std::cout << std::endl;
}

int main()
{
    ClapTrap a("A");
    ScavTrap b("B");
    FragTrap c("C");

    printStatus(a);
    printStatus(b);
    printStatus(c);

    std::cout << "---C attack A--- " << std::endl;
    c.attack("A");
    a.takeDamage(c.getAttackDamage());
    printStatus(a);

    std::cout << "---C repairing---" << std::endl;
    c.beRepaired(20);
    printStatus(c);

    c.highFivesGuys();

    std::cout << "---Energy testing--- " << std::endl;
    for (int i = 0; i < 10; i++)
        c.attack("A");

    printStatus(c);

    std::cout << std::endl;
    return 0;
}
