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

// Macros para los colores
#define RESET   "\033[0m"
#define HEAP_COLOR "\033[34m" // Azul para heap
#define STACK_COLOR "\033[32m" // Verde para stack
#define DELETE_COLOR "\033[31m" // Rojo para delete

int main()
{
    Zombie  *myZombie; //created on heap
    Zombie  *myZombie2;

    std::cout << HEAP_COLOR;
    myZombie = newZombie("David");
    myZombie->announce();
    
    myZombie2 = newZombie("Vica");
    myZombie2->announce();
    std::cout << RESET;
    std::cout << std::endl;
    
    
    //created on stack
    std::cout << STACK_COLOR;
    randomChump("Macaco");
    randomChump("Lalolanda");
    randomChump("Cocorosi");
    std::cout << RESET;
    std::cout << std::endl;

    // delete memory on heap
    std::cout << DELETE_COLOR;
    delete myZombie;
    delete myZombie2;
    std::cout << RESET;
    std::cout << std::endl;

    return (0);
}

