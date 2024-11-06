/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:40:39 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 15:40:42 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#ifndef _WEAPON_
# define _WEAPON_

class Weapon
{
    private:
        std::string type;
    public:
        Weapon();
        ~Weapon();
        Weapon(std::string weapon);
		void	setType(std::string typeName);
        const std::string   getType();
};




#endif

