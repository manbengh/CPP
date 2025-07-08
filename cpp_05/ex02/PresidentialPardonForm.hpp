#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

// class Bureaucrat;
class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        //Getters
        std::string getTarget() const;

        void execute(Bureaucrat const &execute) const ;
};


std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &other);


#endif