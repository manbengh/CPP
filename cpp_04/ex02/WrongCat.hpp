#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        virtual ~WrongCat();

        // void setType(std::string newType);
        std::string getType() const;

        void makeSound() const;
};


#endif