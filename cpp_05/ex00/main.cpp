#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat bob("Bob", 42);
    std::cout << bob;

    std::cout << "Incrementing grade..." << std::endl;
    bob.incrementGrade();
    std::cout << bob;

    std::cout << "Decrementing grade..." << std::endl;
    bob.decrementGrade();
    std::cout << bob;

    Bureaucrat low("LowLevel", 150);
    std::cout << low;
    std::cout << "Trying to decrement at grade 150..." << std::endl;
    low.decrementGrade();
    std::cout << low;

    Bureaucrat high("HighLevel", 1);
    std::cout << high;
    std::cout << "Trying to increment at grade 1..." << std::endl;
    high.incrementGrade();
    std::cout << high;

    return 0;
}
