/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:28 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:45:30 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Default Constructor for Cat Class called" << std::endl;

}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	std::cout << "Copy Constructor for Cat Class called" << std::endl;

}

Cat::~Cat()
{
std::cout << "Destructor for Cat Class called" << std::endl;

}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Copy assigment operator for Cat Class called" << std::endl;

	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << RED << "Meow Meow!!" << RESET << std::endl;
}

std::string	Cat::getType(void) const{return(_type);}
