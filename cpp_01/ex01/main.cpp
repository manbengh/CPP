#include "Zombie.hpp"

int main(int ac, char **av)
{
    Zombie *Zombie;
    (void)av;
    if (ac != 1)
    {
        std::cout << "Wrong number of arguments !" << std::endl;
        return (0);
    }
    Zombie = zombieHorde(3, "zombie");
    delete[] Zombie;
    return 0;
}
