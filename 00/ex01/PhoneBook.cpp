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

// Create libft cpp?
bool is_digits_only(const std::string& str) 
{
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (!std::isdigit(str[i])) 
            return false;
    }
    return true;
}



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

    std::cout << "Please enter the First Name:" << std::endl;
	std::cin >> new_contact.first_name;
    std::cout << "Please enter the Last Name:" << std::endl;
	std::cin >> new_contact.last_name;
    std::cout << "Please enter the Nickname:" << std::endl;
	std::cin >> new_contact.nickname;
    std::cout << "Please enter the Phone Number:" << std::endl;
	std::cin >> new_contact.phone_number;
    while (!std::cin.good() || new_contact.phone_number.length() >= 20 ||  !is_digits_only(new_contact.phone_number))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid phone number (numbers only, max 20)." << std::endl;
        std::cin >> new_contact.phone_number;
    }
    std::cout << "Please enter the Darkest Secret:" << std::endl;
	std::cin >> new_contact.darkest_secret;
    this->_contact_list[this->_next_contact] = new_contact;
    if (this->_next_contact >= 7)
        this->_next_contact = 0;
    else
        this->_next_contact += 1;
    this->_list_size += 1;
    if (this->_list_size >= 8)
        this->_list_size = 8;
    std::cout << "\n--New contact added to Phonebook.--" << std::endl;
    std::cout << "--this->_next_contact.-- " << this->_next_contact << std::endl;
    std::cout << "--this->_list_size.-- " << this->_list_size << std::endl;
}

void    PhoneBook::search_contact()
{
    int ContactIndex = 0;
    Contact contact;

    if (this->_list_size == 0)
    {
        std::cout << "--There's no contact in Phonebook. Please create one.--" << std::endl;
        return ;
    }
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < this->_list_size; i++)
    {
        contact = this->_contact_list[i];
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        contact.print_search_contact();
    }    
    std::cout << "\n-- Select a contact index to see details:"<< std::endl;
    std::cin >> ContactIndex;
    while (!std::cin.good() || ContactIndex <= 0 || ContactIndex > this->_list_size)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index, please choose a number between 1 and " << this->_list_size << ": " << std::endl;
        std::cin >> ContactIndex;
    }
    this->_contact_list[ContactIndex - 1].print_contact();
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

