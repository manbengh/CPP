#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeSign(1), _gradeExec(1) {}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeExec < 1 || gradeSign < 1)
        throw GradeTooHighException();
    else if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}


AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

AForm::~AForm()
{}


//Getters 
std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getGradeExec() const
{
    return (this->_gradeExec);
}

int AForm::getGradeSign() const 
{
    return (this->_gradeSign);
}

bool AForm::getSigned() const
{
    return (this->_signed);
}


// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("AForm Already Signed");
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (_signed)
        throw FormNotSigned();
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}


std::ostream &operator<<(std::ostream &os, const AForm &other)
{
    os << "AForm Name :" << other.getName() << std::endl;
    os << "AForm Grade Exec :" << other.getGradeExec() << std::endl;
    os << "AForm Grade Sign :" << other.getGradeSign() << std::endl;
    if (other.getSigned())
        os << "---> Yes\n";
    else
        os << "---> No\n";

    return (os);
}
