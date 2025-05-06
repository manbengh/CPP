#include "Replace.hpp"

Replace::Replace(std::string s1, std::string s2, std::string oldFile) : s1(s1), s2(s2), oldFile(oldFile)
{
    ;
}

Replace::~Replace()
{
    ;
}

int Replace::process()
{
    std::ifstream myFile(oldFile.c_str());
    if (!myFile)
    {
        std::cout << "File wrong." << std::endl;
        return (1);
    }
    if (s1.empty())
    {
        std::cout << "S1 is empty." << std::endl;
        return (1);
    }
    std::string outFile = std::string(oldFile) + ".replace";
    std::ofstream newFile(outFile.c_str());
    if (!newFile)
    {
        std::cout << "Error when creating outFile." << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(myFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += std::string(s2).length();
        }
        newFile << line << std::endl;
    }
    return (0);
}
