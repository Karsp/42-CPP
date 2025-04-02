/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:42:00 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:42:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"
#include"Cat.hpp"





int main()
{
	size_t count = 4;
	const Animal* meta[count];

try
{
	for (size_t i = 0; i < count; i++)
	{
		if (i < count / 2)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;


	for (size_t i = 0; i < count; i++)
		std::cout << meta[i]->getType() << " " << std::endl;

	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;

	// Check deep copy (copy a Dog)
    Dog originalDog;
    Dog copiedDog = originalDog; // Calls copy constructor
    copiedDog = originalDog; // Calls assignment operator

	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;

	// Check deep copy (copy a Cat)
    Cat originalCat;
    Cat copiedCat = originalCat;
    copiedCat = originalCat;

	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;


	// for (size_t i = 0; i < count; i++)
	// {
	// 	std::cout << meta[i]->makeSound() << " " << std::endl;
	// }


	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;


	std::cout <<  std::endl;

	for (size_t i = 0; i < count; i++)
	{
			delete meta[i];
	}

		
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}


return 0;
}