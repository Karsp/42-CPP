/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:09 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 15:41:10 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Weapon.hpp"

#ifndef _HUMANA_
# define _HUMANA_

class HumanA
{
    private:
        std::string	name;
        Weapon		*weapon;

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void	attack();
};


#endif

