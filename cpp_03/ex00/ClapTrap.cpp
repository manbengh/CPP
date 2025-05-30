#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    this->_name = name;
    std::cout << "ClapTrap " << _name << " called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "Copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;

    std::cout << "Copy assignment operator called." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}


// Getters
std::string ClapTrap::getName()
{
    return (this->_name);
}

int ClapTrap::getHitPoints()
{
    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints()
{
    return (this->_energyPoints);
}

int ClapTrap::getAttackDamage()
{
    return (this->_attackDamage);
}


//Setters

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    this->_attackDamage = attackDamage;
}



void ClapTrap::attack(const std::string& target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else if (getHitPoints() == 0)
        std::cout << getName() << " is out of Hit Points." << std::endl;
    else
        std::cout << getName() << " is out of Energy Points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() == 0)
    {
        std::cout << getName() << " is out of Hit Points." << std::endl;
    }
    std::cout << getName() << " takes " << amount << " points of damage." << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0)
        this->_hitPoints = 0;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{

}
