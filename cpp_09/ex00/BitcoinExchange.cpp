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
            std::cout << "Line ignored (no ',') : " << line << std::endl;
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

void printError(std::string err)
{
    std::cout << "Error : " << err << std::endl;
}

 int isDateCorr(std::string keyFile)
{
    // std::cout << "\nkeyFile =============> " << keyFile << std::endl;
    if (keyFile.size() != 11)
        return (1);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (keyFile[i] != '-')
                return (1);
        }
        else if (!isdigit(keyFile[i]))
            return (1);
    }

    std::stringstream ss;
    std::string year, month, day;
    ss << keyFile;
    if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day, '-'))
    {
        int Y = std::atoi(year.c_str());
        int M = std::atoi(month.c_str());
        int D = std::atoi(day.c_str());

        // std::cout << "Y = " << Y << "\nM = " << M << "\nD = " << D << std::endl;
        if (M >= 1 && M <= 12 && D >= 1 && D <= 31)
        {
            if ((M == 4 || M == 6 || M == 9 || M == 11) && D > 30)
                return (printError("bad input -> " + keyFile),1);
            if (M == 2 && D > 29)
                return (printError("bad input -> " + keyFile),1);
            // bissextile
            if (M == 2 && D == 29)
            {
                if (!(Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)))
                    return (printError("bad input -> " + keyFile),1);
            }
            return 0;
        }
    }
    return (printError("bad input -> " + keyFile),1);
}

int isValCorr(double DValFile)
{
    if (DValFile <= 0)
        return (printError("Not a positive number."), 1);
    if (DValFile > 2147483647)
        return (printError("Too large a number."), 1);
    return (0);
}

int parseLine(std::string &fileLine, std::map<std::string, double> &myFileMap)
{
    size_t pos = fileLine.find('|');
    if (pos == std::string::npos) // NOT FOUND
    {
        std::cout << "Error : bad input (no '|') : " << fileLine << std::endl;
        return 1;
    }

    std::string keyFile = fileLine.substr(0, pos);
    std::string valFile = fileLine.substr(pos + 1);

    if (fileLine.find("date") != std::string::npos && fileLine.find("value") != std::string::npos)
        return (1);

    std::stringstream ss(valFile);
    double DValFile;
    ss >> DValFile;
    if (ss.fail())
    {
        std::cout << "Invalid Value in line --> " << fileLine << std::endl;
        return 1;
    }
   
    // std::cout << keyFile << " --> " << DValFile << std::endl;
   
    if (isDateCorr(keyFile) || isValCorr(DValFile))
        return (1);

    myFileMap[keyFile] = DValFile;
    std::cout << keyFile << " ==> " << DValFile << std::endl;
    return (0);
}




void compareData(std::map<std::string, double> &myData, std::ifstream &myFile)
{
    std::map<std::string, double> myFileMap;
    std::string fileLine;

    (void)myData;
    while (std::getline(myFile, fileLine))
    {
        if (parseLine(fileLine, myFileMap))
            continue ;
        // std::map<std::string, double>::iterator it = myFileMap.begin();
        // std::cout << it->first << " ---- " << it->second << std::endl;
    }
}