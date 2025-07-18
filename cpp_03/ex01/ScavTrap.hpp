#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

    public:

        // ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        
        void guardGate();
        void attack(const std::string &target);
};

// void print_ScavTrap(ScavTrap &clap);
// std::ostream &operator<<(std::ostream &os, const ScavTrap &clap);

#endif