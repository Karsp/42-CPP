/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:24:33 by daviles-          #+#    #+#             */
/*   Updated: 2024/10/10 16:24:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

// int	main(int argc, char **argv)
int	main(void)
{
	std::string	input;
	std::string	seeContact;
	PhoneBook	myPhonebook;

	std::cout << "Phonebook started."<< std::endl;
	
	// std::cout << "Please select an option." << std::endl;
	// std::cout << "-ADD\n-SEARCH\n-EXIT" << std::endl;
	// std::cin >> input;
	while (true)
	{
		std::cout << "\n:: Please select an option ::" << std::endl;
		std::cout << "-ADD\n-SEARCH\n-EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD")
		{
			std::cout << ">> ADD Selected" << std::endl;
			myPhonebook.add_contact();
		}
		else if (input == "SEARCH")
		{
			std::cout << ">> SEARCH Selected" << std::endl;
			myPhonebook.search_contact();
			

		}
		else if (input == "EXIT")
		{
			std::cout << ">> Exiting." << std::endl;
			break;
		}
		else
			std::cout << "XX Invalid option." << std::endl;
		input = "";
	}
	return (0);
}