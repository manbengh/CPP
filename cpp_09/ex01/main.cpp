 #include "RPN.hpp"

void printError(std::string err)
{
    std::cout << "Error " << err << std::endl;
}


int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
        return (printError(": wrong number of args !"), 0);
    myRPN(argv[1]);
    return 0;
}
