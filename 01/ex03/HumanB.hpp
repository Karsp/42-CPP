/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:50 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 15:41:51 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Weapon.hpp"

#ifndef _HUMANB_
# define _HUMANB_

class HumanB
{
    private:
        std::string	name;
        Weapon		weapon;

    public:
        HumanB(std::string name);
        ~HumanB();
        void	attack();
        void     setWeapon(Weapon weapon);
};


#endif