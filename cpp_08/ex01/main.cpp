#include "Span.hpp"

int main()
{
    try
    {
        std::cout << " ---Test 1 ---\n";
        Span test(3);

        test.addNumber(0);
        test.addNumber(1);
        test.addNumber(2);
        test.addNumber(3);

        test.printV();
        std::cout << "Good !\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << " ---Test 2 ---\n";

        Span test(3);

        test.addNumber(5);
        test.addNumber(60);
        test.addNumber(2);
        test.addNumber(0);

        std::cout << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
