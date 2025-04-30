#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie rando;

    rando.nameIt(name);
    rando.announce();
}
