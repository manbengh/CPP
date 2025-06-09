#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
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
    std::cout << "FragTrap " << _name << " is asking for a highfive !✋" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else if (getHitPoints() == 0)
        std::cout << "FragTrap " << _name << " is out of Hit Points." << std::endl;
    else
        std::cout << "FragTrap " << _name << " is out of Energy Points." << std::endl;
}
