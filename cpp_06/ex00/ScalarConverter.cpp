#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

bool isChar(const std::string &str)
{
    if (str.length() == 1 && isalpha(str[0]))
        return true;
    return false;
}

bool isInt(const std::string &str)
{
    char *end;

    std::strtol(str.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    return true;
}

bool isFloat(const std::string &str)
{
    if (str[str.length() - 1] == 'f')
        return true;
    return false;
}

bool isDouble(const std::string &str)
{
    char *end;

    std::strtod(str.c_str(), &end);
    // if ()
}

void ScalarConverter::convert(const std::string &str)
{
    if (isChar(str))
        std::cout << "It's a char" << std::endl;
    else if (isInt(str))
        std::cout << "It's an Int" << std::endl;
    else if (isFloat(str))
        std::cout << "It's a Float" << std::endl;
    
}
