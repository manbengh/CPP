#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();

        // void setType(std::string newType);
        std::string getType() const;

        virtual void makeSound() const;
};


#endif