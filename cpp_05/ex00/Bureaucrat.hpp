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

};


std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);


#endif