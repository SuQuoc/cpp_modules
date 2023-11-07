#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"


class PhoneBook
{
    public:
        PhoneBook(void);
        void search(void);
        void add(void);

    private:
        std::string prompt[5];
        Contact contacts[8];
        int i;
        
        void display_added_contact(void);
        void print_contactlist(int j);
        void display_wished_contact(void);
        
        bool only_whitespace(const std::string& str);
};

#endif