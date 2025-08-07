#include "Serializer.hpp"

//reinterpret_cast ---> Autorise la conversion de tout pointeur en tout autre type pointeur. Autorise également la conversion de tout type entier en tout type pointeur et vice versa.

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &other)
{
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void) other;
    return (*this);
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
