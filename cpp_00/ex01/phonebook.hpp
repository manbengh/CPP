#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <limits>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        bool set_contact();
        void display_contact(int index) const;
        void display_full() const;
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int contact_count;
    public:
        PhoneBook();
        void add_contact();
        void search_contact() const;
};

#endif
