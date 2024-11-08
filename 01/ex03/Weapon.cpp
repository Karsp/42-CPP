/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:40:48 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 15:40:50 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"

Weapon::Weapon()
{
}
Weapon::Weapon(std::string weapon)
{
    this->setType(weapon);
}

Weapon::~Weapon()
{
}

void    Weapon::setType(std::string typeName)
{
    this->type = typeName;
}

const std::string   &Weapon::getType()
{
    return (type);
}

