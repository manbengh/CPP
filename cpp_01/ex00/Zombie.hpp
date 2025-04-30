#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <limits>

class  Zombie
{
    private:
        std::string name;
    
    public:
        void announce (void)
        {
            std::cout << ": BraiiiiiiinnnzzzZ...";
        }
};

#endif
