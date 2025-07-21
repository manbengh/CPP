#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat a("A", 3);
        Bureaucrat b("B", 70);
        Bureaucrat c("C", 25);
        Intern intern;
        AForm *shrubberyForm = intern.makeForm("shrubbery creation", "shrubbs");
        AForm *robotomyForm = intern.makeForm("robotomy request", "robots");
        AForm *presidentialForm = intern.makeForm("presidential pardon", "presidents");

        std::cout << std::endl;
        a.signFrom(*shrubberyForm);
        b.signFrom(*robotomyForm);
        c.signFrom(*presidentialForm);
        std::cout << std::endl;

        AForm *fakeForm = intern.makeForm("test", "myTest");
        a.signFrom(*fakeForm);
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
