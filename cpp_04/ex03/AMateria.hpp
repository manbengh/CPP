#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "ICharacter.hpp"
// #include "MateriaSource.hpp"

class ICharacter;
class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();

        //Getters Setters
        std::string const & getType() const;


        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif