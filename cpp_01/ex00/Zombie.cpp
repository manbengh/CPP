#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "No Name Yet";
}

void Zombie::announce (void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::nameIt(std::string name)
{
    this->name = name;
}
