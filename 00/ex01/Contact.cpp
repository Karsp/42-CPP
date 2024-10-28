/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:57:02 by daviles-          #+#    #+#             */
/*   Updated: 2024/10/10 16:57:03 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"
#include <iomanip>

void    Contact::print_contact()
{
    std::cout << "|";
    if (this->first_name.length() > 9)
        std::cout << this->first_name.substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << this->first_name << "|";
    if (this->last_name.length() > 9)
        std::cout << this->last_name.substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << this->last_name << "|";
    if (this->nickname.length() > 9)
        std::cout << this->nickname.substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << this->nickname << "|";
    if (this->phone_number.length() > 9)
        std::cout << this->phone_number.substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << this->phone_number << "|";
    if (this->darkest_secret.length() > 9)
        std::cout << this->darkest_secret.substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << this->darkest_secret << "|";
    // std::cout << "First Name " + this->first_name << std::endl;
    // std::cout << "Last Name " + this->last_name << std::endl;
    // std::cout << "NickName " + this->nickname << std::endl;
    // std::cout << "Phone number" + this->phone_number << std::endl;
    // std::cout << "Darkest secret " + this->darkest_secret << std::endl;
}

