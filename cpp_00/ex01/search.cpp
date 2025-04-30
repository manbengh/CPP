#include "phonebook.hpp"

//SEARCH
std::string format_field(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    while (str.length() < 10)
        str = " " + str;
    return (str);
};

void Contact::display_contact(int index) const
{
    std::cout << "|" << index << "    "
                << "|" << format_field(first_name)
                << "|" << format_field(last_name)
                << "|" << format_field(nickname)
                << "|\n";
}

void Contact::display_full() const
{
    std::cout << "First Name : " << first_name << "\n";
    std::cout << "Last Name : " << last_name << "\n";
    std::cout << "Nickname : " << nickname << "\n";
    std::cout << "Phone Number : " << phone_number << "\n";
    std::cout << "Darkest Secret : " << darkest_secret << "\n";
}

void PhoneBook::search_contact() const
{
    int index;

    if (contact_count == 0)
    {
        std::cout << "No contact to display.\n";
        return ;
    }
    std::cout << "|Index|First Name|Last Name |Nickname  |\n";
    for (int i = 0; i < contact_count; ++i)
        contacts[i].display_contact(i);
    std::cout << "Enter index : ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= contact_count)
    {
        std::cout << "Invalid index.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nContact Details : \n";
    contacts[index].display_full();
}
