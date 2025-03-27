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

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap Didi; //Fragui is default name
	DiamondTrap Karen("Karen");

	std::cout << std::endl;
	

	Didi.attack(Karen.getName());
	Karen.takeDamage(Didi.getAD());
	
	std::cout << std::endl;

	
	Didi.attack(Karen.getName());
	Karen.takeDamage(Didi.getAD());
	
	std::cout << std::endl;
	
	Didi.whoAmI();
	Karen.whoAmI();

	std::cout << std::endl;
	
	for (size_t i = 0; i < 2; i++)
	{
		Karen.beRepaired(5);
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 8; i++)
	{
		Didi.attack(Karen.getName());
		Karen.takeDamage(Didi.getAD());
		std::cout << std::endl;
	}
	
	Didi.attack(Karen.getName());
	std::cout << std::endl;
	Karen.beRepaired(5);
	std::cout << std::endl;
	


	return (0);
}
