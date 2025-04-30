#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "No Name Yet";
}

Zombie::~Zombie()
{
    name = "Destroyed";
}

void Zombie::announce (void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::nameIt(std::string name)
{
    this->name = name;
}
