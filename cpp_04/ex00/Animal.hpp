
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <fstream>

class Animal 
{
    protected :
        std::string _type;

    public :
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        void setType(std::string newType);
        std::string getType() const;

        virtual void makeSound() const;
};


#endif