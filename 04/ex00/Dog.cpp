/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:51 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:45:52 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Default Constructor for Dog Class called" << std::endl;

}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	std::cout << "Copy Constructor for Dog Class called" << std::endl;

}

Dog::~Dog()
{
std::cout << "Destructor for Dog Class called" << std::endl;

}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Copy assigment operator for Dog Class called" << std::endl;
	
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << BLUE << "Woof Woof!!" << RESET << std::endl;
}

std::string	Dog::getType(void) const{return(_type);}
