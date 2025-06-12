#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    public :
        MateriaSource();
        ~MateriaSource() {}
        void learnMateria(AMateria*) ;
        AMateria* createMateria(std::string const & type);
};

#endif