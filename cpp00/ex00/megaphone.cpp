/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:58:59 by qtran             #+#    #+#             */
/*   Updated: 2023/08/04 14:23:01 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

int main(int argc , char **argv)
{
    int i = 1;
   
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (argc > 1)
    {        
        while (argv[i])
        {
            std::string str = argv[i];
            for (size_t j = 0; j < str.length(); j++)
                std::cout << (char)toupper(str[j]);
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}
