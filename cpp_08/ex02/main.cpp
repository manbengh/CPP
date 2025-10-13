#include "MutantStack.hpp"


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
    std::cout << "top after push-> " << mstack.top() << std::endl;
    std::cout << "size after push -> " << mstack.size() << std::endl;


    std::cout << "\n---COPY TEST---" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "top after copy -> " << s.top() << std::endl;
    std::cout << "size after copy -> " << s.size() << std::endl;


    std::cout << "\n---FIND TEST---" << std::endl;
    // Compatible avec algo STL
    MutantStack<int>::iterator Number = std::find(mstack.begin(),mstack.end(), 5);
    if (Number != mstack.end())
        std::cout << "Number found !!!\n" << std::endl;
    else
        std::cout << "Number not found ...\n" << std::endl;


    mstack.push(10);


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
    
    return 0;
}
