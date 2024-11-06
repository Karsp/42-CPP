/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:19 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/06 14:45:20 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

#define RESET   "\033[0m"
#define MAGENTA "\033[0;35m"
#define GREEN "\033[32m"
#define RED "\033[31m"

int main()
{

    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();


    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();

    return 0;
}

// int main()
// {
    
//     std::string msg = "HI THIS IS BRAIN";
//     std::string *stringPTR = &msg;
//     std::string &stringREF = msg;


//     std::cout << GREEN;
//     std::cout << "--The memory address of" << std::endl;
//     std::cout << "The string variable: "<< &msg << std::endl;
//     std::cout << "Held by stringPTR: "<< &stringPTR << std::endl;
//     std::cout << "Held by stringREF: "<< &stringREF << std::endl;
//     std::cout << RESET;
//     std::cout << std::endl;

//     std::cout << MAGENTA;
//     std::cout << "--The value of" << std::endl;
//     std::cout << "The string variable: "<< msg << std::endl;
//     std::cout << "The value pointed to by stringPTR: "<< *stringPTR << std::endl;
//     std::cout << "The value pointed to by stringREF: "<< stringREF << std::endl;
//     std::cout << RESET;
//     std::cout << std::endl;

//      return (0);
// }
