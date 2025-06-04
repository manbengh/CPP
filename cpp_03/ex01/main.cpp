#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    ClapTrap a("A");
    ScavTrap s("S");

    print_claptrap(a);
    print_claptrap(s);

    std::cout << "--- S attacks A ---" << std::endl;
    s.attack("A");
    a.takeDamage(s.getAttackDamage());
    print_claptrap(a);
    print_claptrap(s);

    a.setAttackDamage(3);
    s.setAttackDamage(1);

    std::cout << "--- A attacks S ---" << std::endl;
    a.attack("S");
    s.takeDamage(a.getAttackDamage());
    print_claptrap(a);
    print_claptrap(s);

    s.beRepaired(1);

    std::cout << "--- S repaired ---" << std::endl;
    print_claptrap(a);
    print_claptrap(s);

    s.guardGate();

    std::cout << std::endl;
}
