# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("Default"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ScavTrap " << getName() << " created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ScavTrap " << getName() << " called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
    *this = other;
    std::cout << "Copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    this->_name = other._name;
    this->_attackDamage = other._attackDamage;
    this->_energyPoints = other._energyPoints;
    this->_hitPoints = other._hitPoints;
    std::cout << "Copy assignment operator called." << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " destroyed." << std::endl;
}



void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else if (getHitPoints() == 0)
        std::cout << "ScavTrap " << getName() << " is out of Hit Points." << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " is out of Energy Points." << std::endl;
}
