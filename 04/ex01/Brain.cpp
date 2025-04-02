/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:10:21 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/02 15:10:24 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
	std::cout << YELLOW <<  "Default Constructor for Brain Class called" << RESET << std::endl;

}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++) 
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << YELLOW <<  "Copy Constructor for Brain Class called" << RESET << std::endl;

}

Brain::~Brain()
{
std::cout << YELLOW <<  "Destructor for Brain Class called" << RESET << std::endl;

}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << YELLOW <<  "Copy assigment operator for Brain Class called" << RESET << std::endl;
	
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++) 
		{
			this->ideas[i] = rhs.ideas[i];
		}

	}
	return (*this);
}
