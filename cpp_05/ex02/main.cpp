#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Shrubbery test
    try
    {
        std::cout << "--- Shrubbery Test 1 ---" << std::endl;
        Bureaucrat B1("B1", 50);
        ShrubberyCreationForm form("myForm1");
        form.beSigned(B1);
        form.execute(B1);
        std::cout << "ShrubberyCreationForm executed !" << std::endl; 
    }
    catch(const std::exception& exp)
    {
        std::cerr << exp.what() << '\n';
    }
    std::cout << std::endl;


    //PresidentialPardonForm
    try
    {
        std::cout << "--- PresidentialPardonForm Test 1 ---" << std::endl;
        Bureaucrat B2("B2", 50); // Grade insuffisant pour exec
        PresidentialPardonForm form1("Target1");

        form1.beSigned(B2); // B2 peut signer
        form1.execute(B2);  // Mais pas exécuter (-> exception)
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::cout << "--- PresidentialPardonForm Test 2 ---" << std::endl;
        Bureaucrat B3("B3", 5); // Grade suffisant
        PresidentialPardonForm form2("Target2");

        form2.beSigned(B3); // B3 signe
        form2.execute(B3);  // B3 exécute
        std::cout << "PresidentialPardonForm executed successfully!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;


    //RobotomyRequestForm
    try
    {
        std::cout << "--- RobotomyRequestForm Test ---" << std::endl;
        Bureaucrat B4("B4", 3);
        RobotomyRequestForm form4("Target4");

        form4.beSigned(B4);
        form4.execute(B4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
