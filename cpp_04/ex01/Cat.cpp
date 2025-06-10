#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    _type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat &other) : brain(new Brain(*other.brain))
{
    this->_type = other._type;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
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


std::string Cat::getBrainIdea(int i)
{
    return (brain->getIdea(i));
}

void Cat::setBrainIdea(int i, std::string newIdea)
{
    brain->setIdea(i, newIdea);
}
