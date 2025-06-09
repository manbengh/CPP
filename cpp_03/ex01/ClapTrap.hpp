#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cmath>

class ClapTrap
{
    protected:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:

        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();        
        
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        
        void setName(std::string name);
        void setHitPoints(int hitPoints);
        void setEnergyPoints(int energyPoints);
        void setAttackDamage(int attackDamage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

void print_claptrap(ClapTrap &clap);
std::ostream &operator<<(std::ostream &os, const ClapTrap &clap);

#endif