#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

// class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) ;
        ~ShrubberyCreationForm();

        //Getters
        std::string getTarget()const;

        void execute(const Bureaucrat &executor) const;
};


std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &other);


#endif