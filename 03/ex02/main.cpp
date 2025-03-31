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

#include "FragTrap.hpp"

int	main()
{
	FragTrap Nixon; //Fragui is default name
	FragTrap Ken("Ken");

	std::string FragTrap_1 = "Fragui";
	std::string FragTrap_2 = "Ken";

	std::cout << std::endl;
	
	Nixon.attack(FragTrap_2);
	Ken.takeDamage(30);
	
	std::cout << std::endl;

	Ken.attack(FragTrap_1);
	Nixon.takeDamage(30);

	std::cout << std::endl;

	Ken.highFivesGuys();
	Nixon.highFivesGuys();

	std::cout << std::endl;
	
	for (size_t i = 0; i < 2; i++)
	{
		Ken.beRepaired(5);
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 8; i++)
	{
		Nixon.attack(FragTrap_2);
		Ken.takeDamage(30);
		std::cout << std::endl;
	}
	
	Nixon.attack(FragTrap_2);
	std::cout << std::endl;
	Ken.beRepaired(5);
	std::cout << std::endl;
	


	return (0);
}
