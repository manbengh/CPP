#include "Weapon.hpp"

Weapon::Weapon()
{
    type = "Typeless";
}

Weapon::Weapon(const std::string &type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    ;
}

const std::string &Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string mytype)
{
    this->type = mytype;
}
