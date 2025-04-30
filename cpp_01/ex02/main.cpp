#include <iostream>
#include <limits>

int main()
{
    std::string c = "HI THIS IS BRAIN";
    std::string *stringPTR = &c;
    std::string &stringREF = c;

    std::cout << &c << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << "\n\n";

    std::cout << c << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}
