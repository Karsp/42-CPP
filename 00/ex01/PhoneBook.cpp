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



    std::cout << "Please enter the Darkest Secret:" << std::endl;
	std::cin >> new_contact.darkest_secret;
    this->_contact_list[this->_next_contact] = new_contact;
    // std::cout << "Your name " + first_name << std::endl;

}

void    PhoneBook::print_contact()
{
    std::cout << "Name " + this->_contact_list->first_name << std::endl;

}


