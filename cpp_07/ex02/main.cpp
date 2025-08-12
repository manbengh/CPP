#include "Array.hpp"

int main()
{
    Array<int> array(5);
    Array<int> copyArr = array;
    std::cout << array.size() << std::endl;
    std::cout << copyArr.size() << std::endl;

    // try
    // {
        
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
}