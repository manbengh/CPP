#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Bureaucrat B1("B1", 5);
        Form F1("F1", 10, 50);

        std::cout << B1;
        std::cout << F1;
        B1.signFrom(F1);
        std::cout << F1;

    }
    catch (const std::exception &exp)
    {
        std::cerr <<exp.what();
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat B2("B2", 40);
        Form F2("F2", 30, 50);

        std::cout << B2;
        std::cout << F2;
        B2.signFrom(F2);
        std::cout << F2;
    }
    catch (const std::exception &exp)
    {
        std::cerr << exp.what();
    }

    std::cout << std::endl;

    try 
    {
        Bureaucrat B3("B3", 12);
        Form F3("F3", 151, 20);
    }
    catch (const std::exception &exp)
    {
        std::cerr << exp.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat B4("B4", 3);
        Form F4("F4", 10, 60);
        std::cout << B4;
        std::cout << F4;
        B4.signFrom(F4);
        std::cout << F4;
        B4.signFrom(F4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

