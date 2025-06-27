#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    _name = name;
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    this->_name = other._name;
    this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->_name = other._name;
    this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}


std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}


void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
    {
        std::cout << "Can't increment anymore." << std::endl;
        return ;
    }
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
    {
        std::cout << "Can't decrement anymore." << std::endl;
        return ;
    }
    _grade++;
}



std::ostream &operator<<(std::ostream &os, const Bureaucrat&other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
    return (os);
}
