#include "iter.hpp"

template<typename T>
void myPrint(T &str)
{
    std::cout << str;
}

int main()
{
    std::string sTab[] = { "one ", "two ", "three"};
    int iTab[] = {1, 2, 3, 4, 5, 6};
    double dTab[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    iter(sTab, 3, myPrint<std::string>);
    std::cout << "\n";
    iter(iTab, 5, myPrint<int>);
    std::cout << "\n";
    iter(dTab, 1, myPrint<double>);
    std::cout << "\n";
    
    return (0);
}
