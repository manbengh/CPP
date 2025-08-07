#include "Serializer.hpp"

int main()
{
    Data data;
    data.myData = 123;

    std::cout << "--- ORIGINAL ---" << std::endl;
    std::cout << "myData ==> " << data.myData << std::endl;
    std::cout << "add data ==> " << &data << std::endl;

    std::cout << '\n' << "--- SERIALIZED ---" << std::endl;
    uintptr_t Ser = Serializer::serialize(&data);
    std::cout << "serialized data ==> " << Ser << std::endl;

    std::cout << '\n' << "--- DESERIALIZED ---" << std::endl;
    Data *Des = Serializer::deserialize(Ser);
    std::cout << "deserialized data ==> " << Des << std::endl;
    std::cout << "deserialized myData ==> " << Des->myData << std::endl;
}