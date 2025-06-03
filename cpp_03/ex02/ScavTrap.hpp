#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:

        ScavTrap();
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