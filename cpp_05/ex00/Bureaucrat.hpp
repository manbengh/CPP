#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <fstream>

class Bureaucrat
{
    private:
        std::string _name;
        int _grade;

    public:
        Bureaucrat();
        // Bureaucrat(const Bureaucrat &other);
        // Bureaucrat &operator=(const Bureaucrat &other);
        virtual ~Bureaucrat();

        // GradeTooHighException
        // GradeTooLowException

        std::string getName();
        int getGrade();

};



#endif