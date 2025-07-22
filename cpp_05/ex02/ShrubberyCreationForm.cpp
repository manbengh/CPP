#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(" ShrubberyCreationForm", 145, 137), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(" ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other.getTarget())
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other.getTarget();
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}


//Getter
std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == false)
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    std::string fileName(_target + "_shrubbery");
    std::ofstream file(fileName.c_str());
    if (file)
    {
        file << "        ccee88oo\n"
                "     C8O8O8Q8PoOb o8oo\n"
                "  dOB69QO8PdUOpugoO9bD\n"
                "CgggbU8OU qOp qOdoUOdcb\n"
                "    6OuU  /p u gcoUodpP\n"
                "      \\\\//  /douUP\n"
                "        \\\\////\n"
                "         |||/\\\n"
                "         |||\\/\n"
                "         |||||\n"
                "   .....//||||\\....\n";
    }
    else
        std::cout << "Failed to open file : " << fileName << std::endl;
    file.close();
}
