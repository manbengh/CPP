#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    ScalarConverter scalar;

    if (ac == 2)
    {
        scalar.convert(av[1]);
    }
    else
        std::cout << "Wrong number of arguments !" << std::endl;
    return (0);
}