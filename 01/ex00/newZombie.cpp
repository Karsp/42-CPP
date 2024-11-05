/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:54 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/05 16:17:56 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"


Zombie* Zombie::newZombie( std::string name )
{
    Zombie *zombie;
	
	zombie = new Zombie;
	zombie->name = name;
	return (zombie);
}
