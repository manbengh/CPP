#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include <string>
#include <fstream>

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;

    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        //Getters
        std::string getName() const;
        int getGradeSign() const;
        int getGradeExec() const;
        bool getSigned()const ;

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

        // FormAlreadySigned
        class FormAlreadySigned : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        void beSigned(Bureaucrat &bureaucrat);

};


std::ostream &operator<<(std::ostream &os, const Form &other);


#endif