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
//     ClapTrap b("B");

//     print_claptrap(a);

//     std::cout << std::endl;

//     a.attack("B");
//     b.takeDamage(a.getAttackDamage());

//     std::cout << "Energy points after attack -> " << b.getEnergyPoints() << std::endl;
//     std::cout << "Hit points after attack -> " << b.getHitPoints() << std::endl;
//     // a.beRepaired(2);
//     // std::cout << a.getEnergyPoints() << std::endl;
//     std::cout << std::endl;

//     a.getAttackDamage(); 
//     std::cout << "Energy points after getAttackDamage -> " << a.getEnergyPoints() << std::endl;
//     std::cout << "Hit points after getAttackDamage -> " << a.getHitPoints() << std::endl;
//     std::cout << std::endl;

//     a.beRepaired(3);
//     std::cout << "Hit points -> " << a.getHitPoints() << std::endl;
//     std::cout << "Energy points -> " << a.getEnergyPoints() << std::endl;

//     std::cout << std::endl;
// }



int main()
{
    ClapTrap a("A");

    print_claptrap(a);

    std::cout << "\n--- État initial ---" << std::endl;
    std::cout << "HP: " << a.getHitPoints() << ", Energy: " << a.getEnergyPoints() << ", Damage: " << a.getAttackDamage() << std::endl;

    std::cout << "\n--- Attaque ---" << std::endl;
    a.attack("Ennemi");

    std::cout << "\n--- Dégâts reçus (5) ---" << std::endl;
    a.takeDamage(5);

    std::cout << "\n--- Réparation (3) ---" << std::endl;
    a.beRepaired(3);

    std::cout << "\n--- État final ---" << std::endl;
    std::cout << "HP: " << a.getHitPoints() << ", Energy: " << a.getEnergyPoints() << ", Damage: " << a.getAttackDamage() << std::endl;

    return 0;
}

