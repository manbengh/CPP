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
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string name, std::string target)const;

        class FormDoesNotExist : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

};


// std::ostream &operator<<(std::ostream &os, const Intern &other);


#endif