#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:

        // FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();
        
        void highFivesGuys(void);
        void attack(const std::string &target);
};

// void print_FragTrap(FragTrap &clap);
// std::ostream &operator<<(std::ostream &os, const FragTrap &clap);

#endif