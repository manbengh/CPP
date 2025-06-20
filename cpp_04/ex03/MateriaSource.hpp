#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#pragma once

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
    private:
        AMateria *_materias[4];

    public :
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();

        void learnMateria(AMateria*) ;
        AMateria* createMateria(std::string const & type);
};

#endif