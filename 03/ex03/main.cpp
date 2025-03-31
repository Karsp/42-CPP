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
	DiamondTrap Didi; //Monstrap is default name
	DiamondTrap Karen("Karen");

	std::string FragTrap_1 = "Monstrap";
	std::string FragTrap_2 = "Karen";


	Didi.attack(FragTrap_2);

	std::cout << std::endl;

	Karen.takeDamage(30);

	std::cout << std::endl;
	
	Karen.attack(FragTrap_1);

	std::cout << std::endl;

	Didi.takeDamage(30);

	std::cout << std::endl;
	
	Didi.whoAmI();
	Karen.whoAmI();
	
	std::cout << std::endl;

	Karen.beRepaired(5);

	std::cout << std::endl;

	Karen.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
