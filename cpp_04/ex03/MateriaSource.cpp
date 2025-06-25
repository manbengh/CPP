#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i] != NULL)
            {
                delete _materias[i];
                _materias[i] = NULL;
            }
            if (other._materias[i] != NULL)
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i] != NULL)
            {
                delete _materias[i];
                _materias[i] = NULL;
            }
            if (other._materias[i] != NULL)
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete(_materias[i]);
}



void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        std::cout << "No Materia to learn from." << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            std::cout << "Materia source learned." << std::endl;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return (_materias[i]->clone());
        }
    }
    return (NULL);
}
