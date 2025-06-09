#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // std::cout << "--- Creating ScavTrap ---" << std::endl;
    ScavTrap s1("A");
    print_claptrap(s1);

    // std::cout << "\n--- Testing actions ---" << std::endl;
    s1.attack("B");
    s1.takeDamage(30);
    s1.beRepaired(15);
    s1.guardGate();
    print_claptrap(s1);

    std::cout << "\n--- Copy Constructor ---" << std::endl;
    ScavTrap s2(s1);

    std::cout << "\n--- Copy Assignment ---" << std::endl;
    ScavTrap s3("C");
    s3 = s1;

    std::cout << std::endl;
    return 0;
}
