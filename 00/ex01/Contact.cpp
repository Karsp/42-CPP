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

void    Contact::print_search_contact()
{
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
        std::cout << std::setw(10) << this->nickname << "|" << std::endl;
}

void    Contact::print_contact()
{
    std::cout << "///////////////////////////////////" << std::endl;
    std::cout << "First Name: " + this->first_name << std::endl;
    std::cout << "Last Name: " + this->last_name << std::endl;
    std::cout << "NickName: " + this->nickname << std::endl;
    std::cout << "Phone number: " + this->phone_number << std::endl;
    std::cout << "Darkest secret: " + this->darkest_secret << std::endl;
    std::cout << "///////////////////////////////////" << std::endl;
}

void	Contact::set_fn(std::string line)
{
	this->first_name = line;
}

void	Contact::set_ln(std::string line)
{
	this->last_name = line;
}

void	Contact::set_nn(std::string line)
{
	this->nickname = line;
}

void	Contact::set_pn(std::string line)
{
	this->phone_number = line;
}

void	Contact::set_ds(std::string line)
{
	this->darkest_secret = line;
}
std::string Contact::get_fn(void) 
{
	return this->first_name;
}

std::string Contact::get_ln(void) 
{
	return this->last_name;
}

std::string Contact::get_nn(void) 
{
	return this->nickname;
}

std::string Contact::get_pn(void) 
{
	return this->phone_number;
}

std::string Contact::get_ds(void) 
{
	return this->darkest_secret;
}