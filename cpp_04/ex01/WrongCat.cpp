#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "WrongCat created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
    this->_type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed." << std::endl;
}


//Getter + Setter

// void WrongCat::setType(std::string newType)
// {
//     this->_type = newType;
// }

std::string WrongCat::getType() const
{
    return (_type);
}



void WrongCat::makeSound() const
{
    std::cout << "Wrong Meow" << std::endl;
}
