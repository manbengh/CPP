#include "ICharacter.hpp"

Character::Character(std::string type)
{
    this->_type = type;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destroyed." << std::endl;
}

void Character::equip(AMateria *m)
{}

void Character::unequip(int idx)
{}

void Character::use(int idx, ICharacter &target)
{}

