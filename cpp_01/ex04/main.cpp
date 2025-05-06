#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of parameters." << std::endl;
        return (1);
    }
    Replace replacer(argv[2], argv[3], argv[1]);
    if (!replacer.process())
        return (1);
    // std::string s1 = argv[2];
    // std::string s2 = argv[3];
    // std::string oldFile = argv[1];
    // std::ifstream myFile(oldFile.c_str());
    // if (!myFile)
    // {
    //     std::cout << "File wrong." << std::endl;
    //     return (1);
    // }
    // if (s1.empty())
    // {
    //     std::cout << "S1 is empty." << std::endl;
    //     return (1);
    // }
    // std::string outFile = std::string(oldFile) + ".replace";
    // std::ofstream newFile(outFile.c_str());
    // if (!newFile)
    // {
    //     std::cout << "Error when creating outFile." << std::endl;
    //     return (1);
    // }
    // std::string line;
    // while (std::getline(myFile, line))
    // {
    //     size_t pos = 0;
    //     while ((pos = line.find(s1, pos)) != std::string::npos)
    //     {
    //         line.erase(pos, s1.length());
    //         line.insert(pos, s2);
    //         pos += std::string(s2).length();
    //     }
    //     newFile << line << std::endl;
    // }
    return (0);
}
