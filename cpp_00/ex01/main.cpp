#include "phonebook.hpp"

int main()
{
    PhoneBook phone_book;
    std::string my_commands;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT) : ";
        while (1)
        {
            std::getline(std::cin, my_commands);
            if (std::cin.eof())
                return 0;
            else
                break ;
        }
        if (my_commands == "ADD")
            phone_book.add_contact();
        else if (my_commands == "SEARCH")
            phone_book.search_contact();
        else if (my_commands == "EXIT")
            return 0;
        else
            std::cout << "Unknown command.\n";
    }
}
