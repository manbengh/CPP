#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << getName() << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    this->_name = name;
    std::cout << "ClapTrap " << getName() << " called." << std::endl;
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
    std::cout << "ClapTrap " << getName() << " destroyed." << std::endl;
}


// Getters
std::string ClapTrap::getName() const
{
    return (this->_name);
}

int ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

int ClapTrap::getAttackDamage() const
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
        std::cout << "ClapTrap " << getName() << " is out of Hit Points." << std::endl;
    else
        std::cout << "ClapTrap " << getName() << " is out of Energy Points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() == 0)
    {
        std::cout << getName() << " is out of Hit Points." << std::endl;
        return ;
    }
    std::cout << getName() << " takes " << amount << " points of damage." << std::endl;
    setHitPoints(getHitPoints() - amount);
    if (getHitPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
        this->_hitPoints = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoints() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " is out of Energy Points." << std::endl;
        return;
    }
    else if (getHitPoints() == 10)
    {
        std::cout << "ClapTrap " << getName() << " is perfectly healthy." << std::endl;
        return;
    }
    setEnergyPoints(getEnergyPoints() - 1);
    if (getHitPoints() + amount > 10)
    {
        setHitPoints(10);
        std::cout << "ClapTrap " << getName() << " is perfectly healthy." << std::endl;
        return;
    }
    setHitPoints(getHitPoints() + amount);
}



void print_claptrap(ClapTrap &clap)
{
    std::cout << "---- " << clap.getName() << " ---- " << std::endl;
    std::cout << "HitPoints : " << clap.getHitPoints() << std::endl;
    std::cout << "EnergyPoints : " << clap.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage : " << clap.getAttackDamage() << std::endl;
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &claptrap)
{
    os << "Name : " << claptrap.getName() << std::endl;
    os << "HitPoints : " << claptrap.getHitPoints() << std::endl;
    os << "EnergyPoints : " << claptrap.getEnergyPoints() << std::endl;
    os << "AttackDamage : " << claptrap.getAttackDamage() << std::endl;
    return (os);
}
