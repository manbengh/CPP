#include "MutantStack.hpp"

// int main()
// {
//     MutantStack<int> test;

//     std::vector<int>::iterator;

//     MutantStack<int>::iterator iter = test.begin();

//     // std::stack<int> test;

    
//     for (int i = 1; i < 6; i++)
//     {
//         test.push(i);
//         std::cout << ;
//     }

//     std::cout << "begin --> " << *test.begin() << std::endl;
//     std::cout << "end --> "<< *test.end() << std::endl;

// }

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}