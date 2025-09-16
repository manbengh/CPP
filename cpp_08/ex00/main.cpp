#include "easyfind.hpp"

// void DisplayI(int i)
// {
//     std::cout<< i << std::endl;
// }

// int main()
// {
//     std::list<int> lst;

//     lst.push_back(10);
//     lst.push_back(20);
//     lst.push_back(5);
//     lst.push_front(550);
//     std::for_each(lst.begin(), lst.end(), DisplayI);
// }



int main()
{
    try
    {
        std::list<int> test;
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);

        std::cout << "--- Success ---" << std::endl;
        std::cout << *easyfind(test, 2) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::vector<int> test;
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);

        std::cout << "--- Fail ---" << std::endl;
        std::cout << *easyfind(test, 5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
