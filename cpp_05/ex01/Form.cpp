#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeSign(1), _gradeExec(1) {}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeExec < 1 || gradeSign < 1)
        throw GradeTooHighException();
    else if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}


Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

Form::~Form()
{}


//Getters 
std::string Form::getName() const
{
    return (this->_name);
}

int Form::getGradeExec() const
{
    return (this->_gradeExec);
}

int Form::getGradeSign() const 
{
    return (this->_gradeSign);
}

bool Form::getSigned() const
{
    return (this->_signed);
}


const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char *Form::FormAlreadySigned::what() const throw()
{
    return ("Form Already Signed");
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (_signed)
        throw FormAlreadySigned();
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}


std::ostream &operator<<(std::ostream &os, const Form &other)
{
    os << "Form Name :" << other.getName() << std::endl;
    os << "Form Grade Exec :" << other.getGradeExec() << std::endl;
    os << "Form Grade Sign :" << other.getGradeSign() << std::endl;
    if (other.getSigned())
        os << "---> Yes\n";
    else
        os << "---> No\n";

    return (os);
}
