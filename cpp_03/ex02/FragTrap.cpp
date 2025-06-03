#include "FragTrap.hpp"

FragTrap::FragTrap() : _name("Default"), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "FragTrap " << _name << " created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "FragTrap " << _name << " called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &other)
{
    *this = other;
    std::cout << "Copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;

    std::cout << "Copy assignment operator called." << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}



void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " is asking for a highfive." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else if (getHitPoints() == 0)
        std::cout << "FragTrap " << getName() << " is out of Hit Points." << std::endl;
    else
        std::cout << "FragTrap " << getName() << " is out of Energy Points." << std::endl;
}
