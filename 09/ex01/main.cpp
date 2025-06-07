/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:23:30 by daviles-          #+#    #+#             */
/*   Updated: 2025/06/07 13:23:32 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
    	std::cerr << "Usage: ./RPN [int to operate in RPN]" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			RPN	tmp(argv[1]);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "Operation error, exiting program." <<std::endl;
		}
	}
	return (0);
}
