#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include <iostream>
#include <string>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;
class PresidentialPardonForm
{
    private:
        const std::string _target;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name, int gradeSign, int gradeExec);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        //Getters
        // std::string getName() const;
        // int getGradeSign() const;
        // int getGradeExec() const;
        // bool getSigned()const ;


};


std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &other);


#endif