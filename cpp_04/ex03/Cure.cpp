#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other)
{
    this->_type = other._type;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Cure::~Cure()
{}

// std::string const &Cure::getType() const
// {
//     return (this->_type);
// }

AMateria *Cure::clone() const
{
    // AMateria *tmp = new Cure(*this);
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
