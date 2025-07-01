#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat test1("test1", 1);
        std::cout << test1;
        test1.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test1 : "<< e.what() <<std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat test2("test2", 151);
        std::cout << test2;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test2 : " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat test3("Test3", 0);
        std::cout << test3;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test3 : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat test4("Test4", 150);
        std::cout << test4;
        test4.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test4 : " << e.what() << std::endl;
    }
}
