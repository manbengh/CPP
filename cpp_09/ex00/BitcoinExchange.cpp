#include "BitcoinExchange.hpp"

void checkArgs(int argc, char **argv)
{
    if (argc != 2)
        throw std::out_of_range("Wrong number of arguments !");
    std::ifstream fileCheck(argv[1]);
    if (!fileCheck.is_open())
        throw std::out_of_range("Can't open file !");
    fileCheck.close();

}

void checkData(std::map<std::string, double> &myData, std::ifstream &dataFile)
{
    std::string line;
    int i = 0;

    while (std::getline(dataFile, line))
    {
        if (line.empty())
            continue;

        // IGNORER 1ERE LINE
        if (i == 0 && line.find("date") != std::string::npos) 
        {
            std::cout << line << std::endl;
            i++;
            continue;
        }

        size_t pos = line.find(',');
        if (pos == std::string::npos) // NOT FOUND
        {
            std::cout << "Ligne ignorée (pas de séparateur) : " << line << std::endl;
            continue;
        }

        std::string myKey = line.substr(0, pos);
        std::string myValue = line.substr(pos + 1);

        std::stringstream ss(myValue);
        double myDValue;
        ss >> myDValue;
        if (ss.fail())
        {
            std::cout << "Invalid Value in line --> " << line << std::endl;
            continue ;
        }
        myData[myKey] = myDValue;

        i++;
    }
}

void compareData(std::map<std::string, double> &myData, std::ifstream &myFile)
{
    std::map<std::string, double> fileData;
    std::string fileLine;

    // while (std::getline())
    // {
    //     if (parseLine() == 1)
    //     {
    //         std::cout << "Error !\n";
    //         continue ;
    //     }
    // }
}
