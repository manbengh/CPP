#include "PmergeMe.hpp"

void parsing(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        std::string arg(av[i]);
        // std::cout << arg << std::endl;

        int signNum = 0;
        for (int j = 0; arg[j]; j++)
        {
            if (arg[j] == '+' || arg[j] == '-')
            {
                if (j != 0 || ++signNum > 1)
                    throw std::invalid_argument("Error : Invalid arg");
            }
            else if (!isdigit(arg[j]))
                throw std::invalid_argument("Error : Invalid arg");
        }

        int num = std::atoi(av[i]);
        if (num < 0)
            throw std::invalid_argument("Error : No negative numbers");
       
        for (int a = i + 1; av[a]; a++)
        {
            if (std::atoi(av[a]) == num)
                throw std::invalid_argument("Error : Duplicates detected");
        }
    }
}


