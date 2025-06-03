#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
    ClapTrap b("B");
    ScavTrap x("X");

    printStatus(a);
    printStatus(b);
    printStatus(x);

    std::cout << "---A attaque B---" << std::endl;
    a.attack("B");
    b.takeDamage(a.getAttackDamage());
    printStatus(b);

    std::cout << "---B attack A---" << std::endl;
    b.attack("A");
    a.takeDamage(b.getAttackDamage());
    printStatus(a);

    std::cout << "---A Repairing---" << std::endl;
    a.beRepaired(4);
    printStatus(a);

    std::cout << "---X attack A---" << std::endl;
    x.attack("A");
    a.takeDamage(x.getAttackDamage());
    printStatus(a);

    x.guardGate();

    std::cout << "---X Repairing---" << std::endl;
    x.beRepaired(10);
    printStatus(x);

    // std::cout << "---Energie testing---" << std::endl;
    // for (int i = 0; i < 10; ++i)
    //     x.attack("Personne");

    // printStatus(x);

    return 0;
}
