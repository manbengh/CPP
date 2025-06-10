#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "WrongAnimal";
    std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destroyed." << std::endl;
}


//Getter + Setter

void WrongAnimal::setType(std::string newType)
{
    this->_type = newType;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}



void WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimal sound." << std::endl;
}
