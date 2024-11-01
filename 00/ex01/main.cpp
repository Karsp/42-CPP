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
	
	// std::cout << "Please select an option." << std::endl;
	// std::cout << "-ADD\n-SEARCH\n-EXIT" << std::endl;
	// std::cin >> input;
	while (true)
	{
		std::cout << "\n:: Please select an option ::" << std::endl;
		std::cout << "1-ADD\n2-SEARCH\n3-EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD" || input == "1")
		{
			std::cout << ">> ADD Selected" << std::endl;
			myPhonebook.add_contact();
		}
		else if (input == "SEARCH" || input == "2")
		{
			std::cout << ">> SEARCH Selected" << std::endl;
			myPhonebook.search_contact();
			

		}
		else if (input == "EXIT"  || input == "3")
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