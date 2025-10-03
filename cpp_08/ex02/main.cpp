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

    std::cout << "top -> " << mstack.top() << std::endl;
    std::cout << "size -> " << mstack.size() << std::endl;

    std::cout << "\n--- POP ---" << std::endl;
    mstack.pop();

    std::cout << "top after pop -> " << mstack.top() << std::endl;
    std::cout << "size after pop -> " << mstack.size() << std::endl;

    std::cout << "\n--- PUSH ---" << std::endl;
    mstack.push(3);
    mstack.push(96);
    mstack.push(737);
    std::cout << "top -> " << mstack.top() << std::endl;

    std::cout << "\n---Find test---" << std::endl;
    // Compatible avec algo STL
    MutantStack<int>::iterator Number = std::find(mstack.begin(),mstack.end(), 5);
    if (Number != mstack.end())
        std::cout << "Number found !!!\n" << std::endl;
    else
        std::cout << "Number not found ...\n" << std::endl;

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    //test -> mon iterator bidirectionnel
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << "it = " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    return 0;
}
