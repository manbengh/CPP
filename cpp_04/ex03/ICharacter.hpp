#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AMateria.hpp"

class AMateria; // Forward declaration to avoid circular dependency

class ICharacter
{
    public:
        virtual ~ICharacter() {};
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};


class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        AMateria *_floor[60];

    public:
        Character(std::string type);
        Character(const Character &other);
        Character &operator=(const Character &other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};


#endif