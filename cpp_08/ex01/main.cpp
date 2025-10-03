#include "Span.hpp"



int main()
{
    try
    {
        std::cout << " ---Test 1 ---\n";
        Span test(2);

        test.addNumber(0);
        test.addNumber(1);
        test.addNumber(2);
        test.addNumber(2);
        test.addNumber(2);

        test.printV();
        std::cout << "Good !\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\n ---Test 2 ---\n";

        Span test(3);

        test.addNumber(5);
        test.addNumber(60);
        test.addNumber(2);
        test.addNumber(0);

        std::cout << "longestSpan ---> " << test.longestSpan() << std::endl;
        std::cout << "shortestSpan ---> " << test.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\n ---Test 3 ---\n";

        Span test(10);
        std::vector<int> numbers;
        for (int i = 0; i < 10; i++)
            numbers.push_back(i);

        test.rangeIterators(numbers.begin(), numbers.end());

        std::cout << "longestSpan ---> " << test.longestSpan() << std::endl;
        std::cout << "shortestSpan ---> " << test.shortestSpan() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
