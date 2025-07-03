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
    }
    catch (const std::exception &exp)
    {
        std::cerr <<exp.what();
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat B2("B2", 50);
        Form F2("F2", 30, 80);

        std::cout << B2;
        std::cout << F2;
        B2.signFrom(F2);
    }
    catch (const std::exception &exp)
    {
        std::cerr << exp.what();
    }
}
