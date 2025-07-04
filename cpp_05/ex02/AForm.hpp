#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>
#include <string>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;

    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

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
        class AFormAlreadySigned : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        virtual void beSigned(Bureaucrat &bureaucrat) = 0;
        

};


std::ostream &operator<<(std::ostream &os, const AForm &other);


#endif