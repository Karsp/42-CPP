/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:24:33 by daviles-          #+#    #+#             */
/*   Updated: 2024/10/10 16:24:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype> // For isdigit
#include <limits> // For check limits on check int

#include <iomanip> //  needed for std::setw()
// #include <iostream>
// #include <sstream>

PhoneBook::PhoneBook()
{
    // std::cout << "Constructor called" << std::endl;
    this->_list_size = 0;
    this->_next_contact = 0;
    return ;
}

PhoneBook::~PhoneBook()
{
    // std::cout << "Destructor called" << std::endl;
    return ;
}

void    PhoneBook::add_contact()
{
    Contact new_contact;
    // std::string first_name;
    // std::string last_name;
    // std::string nickname;
    // std::string secret;
    // std::string phone_input;

    std::cout << "Please enter the First Name:" << std::endl;
	std::cin >> new_contact.first_name;
    std::cout << "Please enter the Last Name:" << std::endl;
	std::cin >> new_contact.last_name;
    std::cout << "Please enter the Nickname:" << std::endl;
	std::cin >> new_contact.nickname;

    std::cout << "Please enter the Phone Number:" << std::endl;
	std::cin >> new_contact.phone_number;

// Input validation for phone number
    // while (true)
    // {
    //     std::cout << "Please enter the Phone Number (numeric only):" << std::endl;
    //     std::cin >> phone_input;
    //     if (is_numeric(phone_input)) 
    //     {
    //         new_contact.phone_number = phone_input;
    //         break;
    //     } 
    //     else
    //         std::cout << "Invalid input. Please enter a valid phone number (numbers only)." << std::endl;
    // }

    std::cout << "Please enter the Darkest Secret:" << std::endl;
	std::cin >> new_contact.darkest_secret;
    this->_contact_list[this->_next_contact] = new_contact;
    if (this->_list_size > 7)
        this->_list_size = 8;
    if (this->_next_contact >= 7)
        this->_next_contact = 0;
    else
    {
        this->_list_size += 1;
        this->_next_contact += 1;
    }
    // std::cout << "Your name " + first_name << std::endl;
}

// // Function to check if the string is numeric
// bool PhoneBook::is_numeric(const std::string &str) 
// {
//     for (size_t i = 0; i < str.length())
//     {
//         if (!std::isdigit(str[i]))
//             return false; // Return false if a character is not a digit
//     }
//     return true; // Return true if all characters are digits
// }


void    PhoneBook::search_contact()
{
    // std::string ContactIndex = "";
    int ContactIndex = 0;
    // int index = 0;

    if (this->_list_size == 0)
    {
        std::cout << "--There's no contact in Phonebook. Please create one.--" << std::endl;
        return ;
    }
        std::cout << "|   Index   |First Name|Last Name |Nickname  |" << std::endl;
    for (int i = 0; i < this->_list_size; i++)
    {
        std::cout << "|" + this->_contact_list->first_name << std::setw(10) << "|" << std::endl;
        // std::cout << "|" + this->_contact_list->first_name << std::endl;
        // std::cout << "First Name" + this->_contact_list->first_name << std::endl;
        // std::cout << "Last Name" + this->_contact_list->last_name << std::endl;
        // std::cout << "NickName " + this->_contact_list->nickname << std::endl;
        // std::cout << "Darkest secret " + this->_contact_list->darkest_secret << std::endl;

    }    
        std::cout << "Select a contact index to see details:";
		std::cin >> ContactIndex;
        
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //ask again
        std::cout << "Select a contact index to see details:";
		std::cin >> ContactIndex;
    }
    std::cout << "Selected " + ContactIndex;
        // index = std::strtol(ContactIndex);
        // this->_contact_list[index].print_contact();

}

std::string PhoneBook::truncateInfo(std::string str)
{
    int spaces = 10 - str.length();

    if (str.length() >= 10)
    {
        str.resize(9);
    }
    else
    {
        for (int i = 0; i < spaces; i++)
        {
            str += " ";
        }
    }
    return (str);
}

void    PhoneBook::print_contact()
{
    std::cout << "First Name " + this->_contact_list->first_name << std::endl;
    std::cout << "Last Name " + this->_contact_list->last_name << std::endl;
    std::cout << "NickName " + this->_contact_list->nickname << std::endl;
    std::cout << "Phone number" + this->_contact_list->phone_number << std::endl;
    std::cout << "Darkest secret " + this->_contact_list->darkest_secret << std::endl;
}


