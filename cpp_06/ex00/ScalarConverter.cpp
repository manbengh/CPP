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

bool isWord(const std::string &str)
{
    std::cout << "isWord !!" << std::endl;
    if (str.length() != 1)
        return false;
    return true;
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

void printImposs(const std::string &str)
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


void displayChar(const std::string &str)
{
    char c = str[0];
    std::cout << "char: '" << str << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void displayInt(const std::string &str)
{
    long l = std::atol(str.c_str());
    char c = static_cast<char>(l);

    if (std::isprint(c) && l > 0 && l < 127)
        std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << l << std::endl;
    std::cout << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(l) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(l) << std::endl;
}

void displayFloat(const std::string &str)
{
    float f = std::atof(str.c_str());

    if (std::isprint(static_cast<char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << std::fixed << std::setprecision(1) << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void displayDouble(const std::string &str)
{
    double d =std::atof(str.c_str());

    if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << std::fixed << std::setprecision(1) << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
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
            displayChar(str);
            break;
        case 2 :
            displayInt(str);
            break;
        case 3 :
            displayFloat(str);
            break;
        case 4 :
            displayDouble(str);
            break;
        case 5 :
            printImposs(str);
            break;
        default:
            std::cout << "Non displayable character." << std::endl;
            break;
    }
}
