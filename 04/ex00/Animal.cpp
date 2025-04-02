/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:43:08 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:43:12 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("Some extraordinary random Animal")
{
	std::cout << "Default Constructor for Animal Class called" << std::endl;
}

Animal::Animal(const Animal& other):_type(other._type)
{
	std::cout << "Copy Constructor for Animal Class called" << std::endl;

}

Animal::~Animal()
{
std::cout << "Destructor for Animal Class called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Copy assigment operator for Animal Class called" << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "* this animal makes an strage sound *" << std::endl;
}

std::string	Animal::getType() const {return(_type);}