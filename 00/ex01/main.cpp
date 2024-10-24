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
	PhoneBook	myPhonebook;

	std::cout << "Phonebook started."<< std::endl;
	
	std::cout << "Please select an option." << std::endl;
	std::cout << "-ADD\n-SEARCH\n-EXIT" << std::endl;
	std::cin >> input;
	while (input != "EXIT")
	{
		if (input == "ADD")
		{
			std::cout << "ADD Selected" << std::endl;
			myPhonebook.add_contact();
			myPhonebook.print_contact();
		}
		else
			std::cout << "Invalid option." << std::endl;
		input = "";
		std::cout << "Please select an option." << std::endl;
		std::cout << "-ADD\n-SEARCH\n-EXIT" << std::endl;
		std::cin >> input;
	}
	std::cout << "Exiting." << std::endl;
	return (0);
}