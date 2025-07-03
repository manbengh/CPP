#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        std::string _name;
        int _grade;

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        // GradeTooHighException
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        // GradeTooLowException
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signFrom(Form &form);
};


std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);


#endif