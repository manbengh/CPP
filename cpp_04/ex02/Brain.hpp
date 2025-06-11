#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    private :
        std::string ideas[100];

    public :
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        virtual ~Brain();

        //getter setter
        std::string getIdea(int i);
        void setIdea(int i, std::string newIdea);

};


#endif