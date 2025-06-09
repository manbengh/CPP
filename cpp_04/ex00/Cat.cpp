#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat &other)
{
    this->_type = other._type;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;
}


//Getter + Setter

// void Cat::setType(std::string newType)
// {
//     this->_type = newType;
// }

std::string Cat::getType() const
{
    return (_type);
}



void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
