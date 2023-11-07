
#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

void Contact::set_contact_info(int i, std::string input)
{
    this->info[i] = input;
}

std::string Contact::get_contact_info(int i)
{
    return (this->info[i]);
}