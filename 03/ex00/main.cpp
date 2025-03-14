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
	ClapTrap Kirk; //Deffie is default name
	ClapTrap Yild("Yild");

	std::cout << std::endl;
	
	Kirk.attack(Yild.getName());
	Yild.takeDamage(Kirk.getAD());
	
	std::cout << std::endl;
	
	// std::cout << COLOR;
	Kirk.setAD(3);
	// std::cout << RESET;

	std::cout << std::endl;
	
	Kirk.attack(Yild.getName());
	Yild.takeDamage(Kirk.getAD());
	std::cout << std::endl;
	
	for (size_t i = 0; i < 2; i++)
	{
		Yild.beRepaired(5);
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 8; i++)
	{
		Kirk.attack(Yild.getName());
		Yild.takeDamage(Kirk.getAD());
		std::cout << std::endl;
	}
	
	Kirk.attack(Yild.getName());
	std::cout << std::endl;
	Yild.beRepaired(5);
	std::cout << std::endl;
	


	return (0);
}
