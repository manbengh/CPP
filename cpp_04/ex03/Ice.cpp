#include "Ice.hpp"

Ice::Ice() :AMateria("ice")
{}

Ice::Ice(const Ice &other)
{
    this->_type = other._type;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Ice::~Ice()
{}

std::string const &Ice::getType() const
{
    return (this->_type);
}

AMateria *Ice::clone() const
{
    // AMateria *tmp = new Ice(*this);
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
