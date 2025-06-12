#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice
{
    private:
        std::string _type;

    public:
        Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        ~Ice();

        std::string const & getType() const; //Returns the materia type
        AMateria* clone() const;
        void use(ICharacter& target);
};



#endif