#include "AMateria.hpp"

AMateria::AMateria()
{
    this->_type = "Default";
}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}

AMateria::AMateria(const AMateria &other)
{
    _type = other._type;
}


AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{

    (void)target;
}

AMateria::~AMateria()
{
}