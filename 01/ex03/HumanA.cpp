/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:23 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 15:41:29 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanA.hpp"

// HumanA::HumanA()
// {

// }
HumanA::HumanA(std::string name, Weapon weapon)
{
    this->name = name;
    this->weapon = weapon;
}

HumanA::~HumanA()
{

}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}