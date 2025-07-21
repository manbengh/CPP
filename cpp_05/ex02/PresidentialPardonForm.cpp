#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(" PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other.getTarget())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other.getTarget();
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


//Getter
std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == false)
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    std::cout << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
