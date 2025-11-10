#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Wrong number of arguments !" << std::endl;
        return 0;
    }
    PmergeMe MergeMe;
    try
    {
        MergeMe.parsing(av);
        MergeMe.mergeInsertSort();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}