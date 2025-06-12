#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}


AMateria::~AMateria()
{
}