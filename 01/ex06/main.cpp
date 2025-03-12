/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:59 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/08 14:20:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"

int main()
{
	Harl harl_two;

	std::cout << "Trying a debug log" << std::endl;
	harl_two.complain("DEBUG");

	std::cout << "Let's try an info log" << std::endl;

	harl_two.complain("INFO");

	std::cout << "Now show me a warning log" << std::endl;
	harl_two.complain("WARNING");
	std::cout << "Now hit me with an error log" << std::endl;
	harl_two.complain("ERROR");

	std::cout << "very nice, now try an AWESOME complain" << std::endl;

	harl_two.complain("AWESOME");
}