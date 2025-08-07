#ifndef SERIALIZER_CPP
#define SERIALIZER_CPP


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <stdint.h>

class Data
{
    public:
        int myData;
};

class Serializer
{
    private :
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif