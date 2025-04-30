#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    contact_count = 0;
}

//ADD
bool Contact::set_contact()
{
    std::cout << "First Name : ";
    std::getline(std::cin, first_name);
    std::cout << "Last Name : ";
    std::getline(std::cin, last_name);
    std::cout << "Nickname : ";
    std::getline(std::cin, nickname);
    std::cout << "Phone number : ";
    std::getline(std::cin, phone_number);
    std::cout << "Darkest Secret : ";
    std::getline(std::cin, darkest_secret);
    if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty())
    {
        std::cout << "All fields must be filled.\n";
        return false;
    }
    return true;
}

void PhoneBook::add_contact()
{
    Contact new_contact;

    if (!new_contact.set_contact())
        return ;
    if (contact_count < 8)
    {
        contacts[contact_count] = new_contact;
        contact_count++;
    }
    else
    {
        std::cout << "PhoneBook is full, replacing oldest contact.\n";
        for (int i = 0; i < 7; ++i)
            contacts[i] = contacts[i + 1];
        contacts[7] = new_contact;
    }
}
