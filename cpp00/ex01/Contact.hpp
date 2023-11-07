#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
    public:
        Contact(void);
        void set_contact_info(int i, std::string input);
        std::string get_contact_info(int i);
    private:
        std::string info[5];
};

#endif