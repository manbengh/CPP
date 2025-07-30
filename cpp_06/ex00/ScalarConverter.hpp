#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

// class Bureaucrat;

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        void convert(const std::string &conv);
};


// std::ostream &operator<<(std::ostream &os, const ScalarConverter &other);


#endif