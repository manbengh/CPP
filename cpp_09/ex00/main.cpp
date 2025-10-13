#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    try
    {
        check_args(argc, argv);
        std::map<std::string, double> myData;
        std::ifstream myFile(argv[1]);
        checkData(myData, myFile);
    }


    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
