#include "Array.hpp"


int main()
{
    
    try 
    {
        Array<int> array(4);
        
        array[0] = 10;
        array[1] = 20;
        array[2] = 30;
        array[3] = 40;

        std::cout << "--- Print Test ---" << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << array[i] << std::endl;

        std::cout << "\n--- Copy Test ---" << std::endl;
        Array<int> arrayCopy(array);
        for (unsigned int i = 0; i < arrayCopy.size(); i++)
            std::cout << arrayCopy[i] << std::endl;

        std::cout << "\n--- Affect Test ---" << std::endl;
        Array<int> arrayAff;
        arrayAff = array;
        for (unsigned int i = 0; i < arrayAff.size(); i++)
            std::cout << arrayAff[i] << std::endl;
 
        std::cout << "\n --- Failed test ---" << std::endl;
        std::cout << array[9] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
