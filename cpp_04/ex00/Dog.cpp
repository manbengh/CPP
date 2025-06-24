#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other)
{
    this->_type = other._type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destroyed." << std::endl;
}


//Getter + Setter

// void Dog::setType(std::string newType)
// {
//     this->_type = newType;
// }

// std::string Dog::getType() const
// {
//     return (this->_type);
// }



void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}