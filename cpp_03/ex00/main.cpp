#include "ClapTrap.hpp"


int main()
{
    ClapTrap a("A");
    ClapTrap b("B");

    print_claptrap(a);
    print_claptrap(b);

    a.setAttackDamage(1);
    b.setAttackDamage(1);

    std::cout << "--- A attacks B ---" << std::endl;
    a.attack("B");
    b.takeDamage(a.getAttackDamage());
    print_claptrap(a);
    print_claptrap(b);

    std::cout << "--- B attacks A ---" << std::endl;
    b.attack("B");
    a.takeDamage(b.getAttackDamage());
    print_claptrap(a);
    print_claptrap(b);

    a.setAttackDamage(2);
    b.setAttackDamage(2);

    std::cout << std::endl;
    std::cout << "--- A attacks B AGAIN---" << std::endl;
    a.attack("B");
    b.takeDamage(a.getAttackDamage());
    print_claptrap(b);

    std::cout << "--- B attacks A AGAIN---" << std::endl;
    b.attack("B");
    a.takeDamage(b.getAttackDamage());
    print_claptrap(a);
}
