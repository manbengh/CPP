#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    try
    {
        checkArgs(argc, argv);
        std::map<std::string, double> myData;
        std::ifstream dataFile("data.csv");
        checkData(myData, dataFile);
        std::ifstream myFile(argv[1]);
        compareData(myData, myFile);
    }


    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
