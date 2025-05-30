#include "Harl.hpp"

Harl::Harl()
{
    ;
}

Harl::~Harl()
{
    ;
}

void Harl::debug()
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO" << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING" << std::endl;
}

void Harl::error()
{
    std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Unknown level : " << level << std::endl;
}
