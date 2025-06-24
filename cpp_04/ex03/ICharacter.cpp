#include "ICharacter.hpp"

Character::Character(std::string name)
{
    this->_name = name;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 60; i++)
        _floor[i] = NULL;
}

Character::Character(const Character &other)
{
    this->_name = other._name;

    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 60; i++)
        _floor[i] = NULL;

    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
    }

    for (int i = 0; i < 60; i++)
    {
        if (other._floor[i])
            _floor[i] = other._floor[i]->clone();
    }
}


Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;

        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
        }

        for (int i = 0; i < 60; i++)
        {
            delete _floor[i];
            _floor[i] = NULL;
            if (other._floor[i])
                _floor[i] = other._floor[i]->clone();
        }
    }
    return (*this);
}


Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
    for (int i = 0; i < 60; i++)
    {
        if (_floor[i])
            delete _floor[i];
    }
    std::cout << "Character destroyed." << std::endl;
}

std::string const &Character::getName() const
{
    return (this->_name);
}


void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "No Materia to be found." << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << "Materia " << m->getType() << " equipped at index " << i << "." << std::endl;
            return;
        }
    }
    std::cout << "The inventory is full !" << std::endl;
    // delete m;
}

void Character::unequip(int idx)
{
    bool floorFull = true;
    for (int i = 0; i < 60; i++)
    {
        if (_floor[i] == NULL)
        {
            floorFull = false;
            break;
        }
    }
    if (floorFull)
    {
        std::cout << "Floor is full ! Can't unequip anymore." << std::endl;
        return ;
    }
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << "Invalid index or no Materia to unequip." << std::endl;
        std::cout << "idx = " << idx << std::endl;
        return;
    }
    for (int i = 0; i < 60; i++)
    {
        if (!_floor[i])
        {
            _floor[i] = _inventory[idx];
            delete _inventory[idx];
            _inventory[idx] = NULL;
            std::cout << "Materia at index " << idx << " unequiped." << std::endl;
            return;
        }
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
    else
        std::cout << "Invalid index in use function." << std::endl;
}

