#include "ClapTrap.hpp"

// int main()
// {
//     ClapTrap a("A");

//     std::cout << a.getHitPoints() << std::endl;
//     a.attack("B");
//     std::cout << a.getEnergyPoints() << std::endl;
//     a.takeDamage(1);
//     std::cout << "a getHitPoints before --> " << a.getHitPoints() << std::endl;
//     a.beRepaired(1);
//     std::cout << "a getHitPoints after --> " << a.getHitPoints() << std::endl;
// }


// int main()
// {
//     ClapTrap a("A");

//     print_claptrap(a);

//     std::cout << std::endl;

//     a.attack("B");
//     a.attack("B");
//     a.attack("B");
//     a.attack("B");
//     a.attack("B");
//     a.attack("B");
//     std::cout << a.getEnergyPoints() << std::endl;
//     a.beRepaired(2);
//     std::cout << a.getEnergyPoints() << std::endl;

//     std::cout << std::endl;
// }



int main()
{
    std::cout << "Testing ClapTrap constructors and copy operators" << std::endl;

    ClapTrap claptrap_1;
    std::cout << claptrap_1;

    ClapTrap claptrap_2("Claptrap_2");
    std::cout << claptrap_2;

    ClapTrap claptrap_3(claptrap_2);
    std::cout << claptrap_3;

    claptrap_3 = claptrap_2;
    std::cout << claptrap_3;

    claptrap_3 = claptrap_1;
    std::cout << claptrap_3;

    std::cout << "Testing ClapTrap member functions" << std::endl;

    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());

    std::cout << claptrap_1;

    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");

    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(11);

    std::cout << claptrap_2;
    claptrap_2.beRepaired(5);

    std::cout << claptrap_2;
    claptrap_2.beRepaired(6);

    std::cout << claptrap_2;
}
