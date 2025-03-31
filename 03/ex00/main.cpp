/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:16:37 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/14 20:16:40 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Kirk; //Clappie is default name
	ClapTrap Yild("Yild");

	std::string ClapTrap_1 = "Clappie";
	std::string ClapTrap_2 = "Yield";
	std::cout << std::endl;
	
	Kirk.attack(ClapTrap_2);
	Yild.takeDamage(0);
	
	std::cout << std::endl;
	
	Yild.attack(ClapTrap_1);
	Kirk.takeDamage(0);
	std::cout << std::endl;
	
	for (size_t i = 0; i < 2; i++)
	{
		Yild.beRepaired(5);
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 9; i++)
	{
		Kirk.attack(ClapTrap_2);
		Yild.takeDamage(0);
		std::cout << std::endl;
	}
	
	Kirk.attack(ClapTrap_2);
	std::cout << std::endl;
	Yild.beRepaired(5);
	std::cout << std::endl;
	
	return (0);
}
