#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
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


AForm *Intern::makeForm(std::string name, std::string target) const
{
    int i;
    std::string allFroms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *myForm = NULL;
    for (i = 0; i < 3; i++)
    {
        if (name ==allFroms[i])
            break;
    }

    switch (i)
    {
        case 0:
            myForm = new ShrubberyCreationForm(target);
            std::cout << "Intern creates a ShrubberyCreationForm" <<std::endl;
            break;
        case 1:
            myForm = new RobotomyRequestForm(target);
            std::cout << "Intern creates a RobotomyRequestForm" <<std::endl;
            break;
        case 2:
            myForm = new PresidentialPardonForm(target);
            std::cout << "Intern creates a PresidentialPardonForm" <<std::endl;
            break;
    
        default:
            throw FormDoesNotExist();
            break;
    }
    return (myForm);
}

const char *Intern::FormDoesNotExist::what() const throw()
{
    return ("This Form does not exist");
}
