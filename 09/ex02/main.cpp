/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:51:38 by daviles-          #+#    #+#             */
/*   Updated: 2025/06/07 18:51:41 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
    	std::cerr << "Usage: ./PmergeMe [unsigned int to operate in PmergeMe]" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			std::string input;

			for (int i = 1; i < argc; ++i) 
			{
				input += argv[i];
				if (i < argc - 1)
					input += " ";
			}
			PmergeMe	tmp(input);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "Operation error, exiting program." <<std::endl;
			// clear deque and vector?
		}
	}
	return (0);
}
