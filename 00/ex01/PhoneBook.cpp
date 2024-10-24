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

PhoneBook::PhoneBook()
{
    std::cout << "Constructor called" << std::endl;
    this->_list_size = 0;
    this->_next_contact = 0;
    return ;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void    PhoneBook::add_contact()
{
    Contact new_contact;
    // std::string first_name;
    // std::string last_name;
    // std::string nickname;
    // std::string secret;
    // int phone;

    std::cout << "Please enter the First Name:" << std::endl;
	std::cin >> new_contact.first_name;
    std::cout << "Please enter the Last Name:" << std::endl;
	std::cin >> new_contact.last_name;
    std::cout << "Please enter the Nickname:" << std::endl;
	std::cin >> new_contact.nickname;

    std::cout << "Please enter the Phone Number:" << std::endl;
	std::cin >> new_contact.phone_number;

// Input validation for phone number
    // std::string phone_input;
    // while (true) {
    //     std::cout << "Please enter the Phone Number (numeric only):" << std::endl;
    //     std::cin >> phone_input;
        
    //     if (is_numeric(phone_input)) {
    //         new_contact.phone_number = phone_input; // Assign valid numeric input
    //         break; // Exit the loop if input is valid
    //     } else {
    //         std::cout << "Invalid input. Please enter a valid phone number (numbers only)." << std::endl;
    //     }
    // }

// #include <cctype> // For isdigit

// // Function to check if the string is numeric
// bool is_numeric(const std::string &str) {
//     for (char const &c : str) {
//         if (!std::isdigit(c)) return false; // Return false if a character is not a digit
//     }
//     return true; // Return true if all characters are digits
// }



    std::cout << "Please enter the Darkest Secret:" << std::endl;
	std::cin >> new_contact.darkest_secret;
    this->_contact_list[this->_next_contact] = new_contact;
    // std::cout << "Your name " + first_name << std::endl;

}

void    PhoneBook::print_contact()
{
    std::cout << "Name " + this->_contact_list->first_name << std::endl;

}


