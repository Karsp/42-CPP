/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:02:33 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/17 14:02:36 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap Susan; //Scavei is default name
	ScavTrap Morgan("Morgan");

	std::string ScavTrap_1 = "Scavei";
	std::string ScavTrap_2 = "Morgan";
	std::cout << std::endl;
	
	Susan.attack(ScavTrap_2);
	Morgan.takeDamage(20);

	std::cout << std::endl;
	
	Morgan.attack(ScavTrap_1);
	Susan.takeDamage(20);

	std::cout << std::endl;
	
	Morgan.guardGate();
	Susan.guardGate();

	std::cout << std::endl;
	
	for (size_t i = 0; i < 2; i++)
	{
		Morgan.beRepaired(5);
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 8; i++)
	{
		Susan.attack(ScavTrap_2);
		Morgan.takeDamage(20);
		std::cout << std::endl;
	}
	
	std::cout << std::endl;

	Morgan.beRepaired(5);

	std::cout << std::endl;
	
	return (0);
}
