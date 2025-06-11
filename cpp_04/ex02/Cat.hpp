#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *brain;

    public :
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();

        // void setType(std::string newType);
        std::string getType() const;

        virtual void makeSound() const;

        //getter setters ideas
        std::string getBrainIdea(int i);
        void setBrainIdea(int i, std::string newIdea);
};


#endif