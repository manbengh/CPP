#include "BitcoinExchange.hpp"

void check_args(int argc, char **argv)
{
    if (argc != 2)
        throw std::out_of_range("Wrong number of arguments !");
    std::ifstream fileCheck(argv[1]);
    if (!fileCheck.is_open())
        throw std::out_of_range("Can't open file !");
    fileCheck.close();

}

void checkData(std::map<std::string, double> &myData, std::ifstream &myFile)
{
    std::string line;
    int i = 0;

    while (std::getline(myFile, line))
    {
        if (line.empty() && i == 0)
        {
            myFile.close();
            throw std::out_of_range("File is empty !");
        }
        myData.insert(std::pair<int, std::string>(i, line));
        i++;
    }
}
