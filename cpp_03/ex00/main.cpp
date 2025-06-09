#include "ClapTrap.hpp"

int main() {
    ClapTrap a("A");

    a.attack("B");
    a.takeDamage(1);
    a.beRepaired(1);
    a.attack("C");
    a.takeDamage(12);
    a.beRepaired(2);
    a.attack("B"); 
    a.beRepaired(3);

    ClapTrap b = a;
    ClapTrap c("Z");
    c = a;

    return 0;
}
