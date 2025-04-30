#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *myZombie = new Zombie();
    myZombie->nameIt(name);
    return myZombie;
}
