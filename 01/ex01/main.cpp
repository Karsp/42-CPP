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

// Color codes (add on header?)
#define RESET   "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"

int main()
{
    Zombie  *myZombie;
    Zombie  *myZombie2;
    int     N1 = 3;
    int     N2 = 6;

// Horde 1
    std::cout << GREEN;
    myZombie = zombieHorde(N1, "David");
    for (int i = 0; i < N1; i++)
    {
        myZombie[i].announce();
    }
    std::cout << RESET;
    std::cout << std::endl;

// Horde 2
    std::cout << BLUE;
    myZombie2 = zombieHorde(N2, "Martin");
    for (int i = 0; i < N2; i++)
    {
        myZombie2[i].announce();
    }
    std::cout << RESET;
    std::cout << std::endl;
 
//  Free memory
    std::cout << RED;
    delete[] myZombie;
    delete[] myZombie2;
    std::cout << RESET;
    std::cout << std::endl;

    return (0);
}

