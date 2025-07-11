#include "Intern.hpp"

Intern::Intern(std::string name, int grade)
{}

Intern::Intern(const Intern &other)
{
    (void) other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return (*this);
}

Intern::~Intern()
{}


AForm *