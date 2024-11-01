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

	std::cout << "Hello there! Your Awesome Phonebook has started."<< std::endl;
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
		else if (std::cin.eof())
        {
            std::cout << std::flush << std::endl;
            std::cin.clear();
			std::cout << ">> Exiting." << std::endl;
			return (1);
        }
		else
			std::cout << "XX Invalid option. XX" << std::endl;
		input = "";
	}
	return (0);
}