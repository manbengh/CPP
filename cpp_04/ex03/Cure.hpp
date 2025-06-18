#ifndef CURE_HPP
#define CURE_HPP

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:
        std::string _type;

    public:
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        virtual ~Cure();

        virtual AMateria* clone() const ;
        void use(ICharacter& target);

};



#endif