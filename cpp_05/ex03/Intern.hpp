#ifndef INTERN_HPP
#define INTERN_HPP


#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class AForm;
class Intern
{

    public:
        Intern(std::string name, int grade);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);


};


// std::ostream &operator<<(std::ostream &os, const Intern &other);


#endif