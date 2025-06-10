#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();

        // void setType(std::string newType);
        // std::string getType() const;

        virtual void makeSound() const;
};


#endif