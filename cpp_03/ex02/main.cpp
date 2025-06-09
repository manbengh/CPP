#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {
    FragTrap frag("Frag");
    print_claptrap(frag);

    frag.attack("B");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();
    print_claptrap(frag);

    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    FragTrap fragCopy(frag);
    fragCopy.attack("C");

    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    FragTrap anotherFrag("anotherFrag");
    anotherFrag = frag;
    anotherFrag.highFivesGuys();

    return 0;
}
