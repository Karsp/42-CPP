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
    	std::cerr << "usage: ./RPN [expr]" << std::endl;
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
			std::cout << "Error" <<std::endl;
		}
	}
	return (0);
}
