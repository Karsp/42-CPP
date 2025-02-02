/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:15 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/05 16:18:17 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"


void randomChump( std::string name )
{
    Zombie new_zombie;
	
	new_zombie.setName(name);
    new_zombie.announce();
}

