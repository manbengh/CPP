#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

// class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        //Getters
        std::string getTarget() const;

        void execute(Bureaucrat const &execute) const ;
};


// std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &other);


#endif