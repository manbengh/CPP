#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Bureaucrat B1("B1", 10);
        Form F1("F1", 5, 30);

        std::cout << B1 << std::endl;
        std::cout << F1 << std::endl;
        // B1.sign
    }
    catch (const std::exception &exp)
    {
        std::cerr <<exp.what() << std::endl;
    }
}
