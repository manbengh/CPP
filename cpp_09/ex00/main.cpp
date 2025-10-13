#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    try
    {
        check_args(argc, argv);
        std::map<std::string, double> myData;
        checkData(myData, argv[1]);
    }


    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
