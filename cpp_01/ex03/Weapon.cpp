#include "Weapon.hpp"

Weapon::Weapon()
{
    type = "No Type";
}

Weapon::~Weapon()
{
    type = "Destroyed";
}

std::string &Weapon::get_type(void)
{
    return (this->type);
}
