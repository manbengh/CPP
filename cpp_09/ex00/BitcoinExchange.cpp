#include "BitcoinExchange.hpp"

void check_args(int argc, char **argv)
{
    if (argc != 2)
        throw std::out_of_range("Wrong number of arguments !");
    std::ifstream test(argv[1]);
    if (!test.is_open())
        throw std::out_of_range("Can't open file !");
    test.close();
    
}

void checkData(std::map<std::string, double> &myData, char &argv)
{

}
