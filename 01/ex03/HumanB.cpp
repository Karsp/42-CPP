/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:42:21 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 15:42:22 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{

}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
void    HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}