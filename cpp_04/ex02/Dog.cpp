#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog() : brain(new Brain())
{
    _type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->_type = other._type;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        // Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed." << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

//Getter + Setter

// void Dog::setType(std::string newType)
// {
//     this->_type = newType;
// }

std::string Dog::getType() const
{
    return (this->_type);
}

std::string Dog::getBrainIdea(int i)
{
    return (brain->getIdea(i));
}

void Dog::setBrainIdea(int i, std::string newIdea)
{
    brain->setIdea(i, newIdea);
}
