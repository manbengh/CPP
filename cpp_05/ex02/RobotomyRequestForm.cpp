#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(" RobotomyRequestForm", 72, 45), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(" RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other.getTarget())
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other.getTarget();
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


//Getter
std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == false)
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully !" << std::endl;
    else
        std::cout << _target << "'s robotomy failed !" << std::endl;
}
