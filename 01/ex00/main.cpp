/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:16:15 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/05 16:16:17 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int main()
{
    Zombie  myZombie;
    Zombie  myZombie2;

    myZombie.newZombie("David");
    myZombie.announce();
    myZombie2.randomChump("Macaco");
    return (0);
}

