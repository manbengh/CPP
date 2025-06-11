#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created." << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
}


//Getter & Setter

void Brain::setIdea(int i, std::string newIdea)
{
    if (i > 100 || i < 0)
        return ;
    this->ideas[i] = newIdea;
}

std::string Brain::getIdea(int i)
{
    if (i > 100 || i < 0)
        return ("Incorrect Index !");
    return (this->ideas[i]);
}
