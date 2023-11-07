/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:58:59 by qtran             #+#    #+#             */
/*   Updated: 2023/08/01 15:35:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : i(0)
{
    prompt[0] = "Enter First Name: ";
    prompt[1] = "Enter Last Name: ";
    prompt[2] = "Enter Nickname: ";
    prompt[3] = "Enter Phone Number: ";
    prompt[4] = "Enter Darkest Secret: ";
    std::cout << "Enter one of the following commands:" << std::endl;
    std::cout << "- ADD" << std::endl;
    std::cout << "- SEARCH" << std::endl;
    std::cout << "- EXIT" << std::endl << std::endl;
}

//PhoneBook functions
void PhoneBook::add(void)
{
    if (this->i > 7)
        this->i = 0;
    std::string input;
    for (int j = 0; j < 5;)
    {
        std::cout << this->prompt[j];
        std::getline(std::cin, input);
        if(std::cin.eof())
        {
            std::cout << std::endl;
            return ;
        }
        if (input.empty() || only_whitespace(input))
            std::cout << "No requested field can be empty. Fill in the info!" << std::endl;
        else
        {
            this->contacts[this->i].set_contact_info(j, input);
            j++;
        }
    }
    display_added_contact();
    this->i++;
}

bool PhoneBook::only_whitespace(const std::string& str) 
{   
    for (unsigned long j = 0; j < str.length(); j++)
    {
        if (!(std::isspace(str[j])))
            return false;
    }
    return true;
}

void PhoneBook::display_added_contact(void)
{
    std::cout << std::endl << "_____Successfully added contact_____" << std::endl << std::endl;
    for (int j = 0; j < 5; j++)
    {
        std::cout << prompt[j].substr(6) << this->contacts[this->i].get_contact_info(j) << std::endl;
    }
    std::cout << "____________________________________"<< std::endl << std::endl;
}

void PhoneBook::search(void)
{
    std::cout << "All saved contacts:" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;    
    int j = 0;
    while (j < 8 && !(this->contacts[j].get_contact_info(0).empty()))
    {
        print_contactlist(j);
        j++;
    }
    std::cout << "--------------------------------------------" << std::endl;
    display_wished_contact();
}

void PhoneBook::print_contactlist(int j)
{
    int len = 0;
    int spaces = 0;
    std::cout << j + 1 << "        |";
    for (int x = 0; x < 3; x++)
    {
        len = this->contacts[j].get_contact_info(x).length();
        if (len < 10)
        {
            std::cout << this->contacts[j].get_contact_info(x);
            spaces = 10 - len;
            while(spaces > 0)
            {
                std::cout << " ";
                spaces--;
            }
        }
        else
            std::cout << this->contacts[j].get_contact_info(x).substr(0, 9) << ".";
        std::cout << "|";
    }
    std::cout << std::endl;
}

void PhoneBook::display_wished_contact(void)
{
    std::string index;
    int num = 0;
    while (1)
    {
        std::cout << "Give index for wished contact: ";
        std::getline(std::cin, index);
        if(std::cin.eof())
        {
            std::cout << std::endl;
            return ;
        }
        if ((index.length() == 1) && '1' <= index[0] && index[0] <= '8')
            break;
        else
            std::cout << "Wrong index!" << std::endl;
    }
    num = index[0] - '0';
    if (this->contacts[num - 1].get_contact_info(0).empty())
    {
        std::cout << "Sry no saved contact at given index." << std::endl;
        return ;
    }
    std::cout << "____________________________________"<< std::endl << std::endl;
    for (int j = 0; j < 5; j++)
    {
        std::cout << prompt[j].substr(6) << this->contacts[num - 1].get_contact_info(j) << std::endl;
    }
    std::cout << "____________________________________"<< std::endl << std::endl;
}
