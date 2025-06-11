#include "Animal.hpp"

Animal::Animal()
{
    _type = "Animal";
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal &other)
{
    this->_type = other._type;
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destroyed." << std::endl;
}


//Getter + Setter

void Animal::setType(std::string newType)
{
    this->_type = newType;
}

std::string Animal::getType() const
{
    return (this->_type);
}



// void Animal::makeSound() const
// {
//     std::cout << "Generic animal sound." << std::endl;
// }