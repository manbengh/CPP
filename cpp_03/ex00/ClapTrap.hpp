#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cmath>

class ClapTrap
{
    private:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:

        ClapTrap();
        ~ClapTrap();
        // void attack(const std::string& target);

};

// std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif