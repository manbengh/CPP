#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
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
    size_t myDot = str.find('.');

    std::strtod(str.c_str(), &end);
    if (end[0] == '\0' && myDot != std::string::npos)
        return true;
    return false;
}

int checkType(const std::string &str)
{
    if (isChar(str))
        return 1;
    else if (isInt(str))
        return 2;
    else if (isFloat(str))
        return 3;
    else if (isDouble(str))
        return 4;
    if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "-inf" || str == "-inff"|| str == "+inf" || str == "+inff")
        return 5;
    return 0;
}

void printImpo(const std::string &str)
{
    if (str == "nanf" || str == "nan")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (str == "inff" || str == "inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
    }
}


void ScalarConverter::convert(const std::string &str)
{
    if (str.empty())
    {
        std::cout << "String is empty !" << std::endl;
        return ;
    }
    int i = checkType(str);
    switch (i)
    {
        case 1 :
            std::cout << "is Char" << std::endl;
            break;
        case 2 :
            std::cout << "is Int" << std::endl;
            break;
        case 3 :
            std::cout << "is Float" << std::endl;
            break;
        case 4 :
            std::cout << "is Double" << std::endl;
            break;
        case 5 :
            printImpo(str);
            break;
        default:
            std::cout << "Non displayable character." << std::endl;
            break;
    }
}
