#ifndef ICE_HPP
#define ICE_HPP

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        std::string _type;

    public:
        Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        virtual ~Ice();

        std::string const & getType() const; //Returns the materia type
        AMateria* clone() const;
        void use(ICharacter& target);
};



#endif