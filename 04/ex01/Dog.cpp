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
	_brain = new Brain();
	std::cout << BLUE <<  "Default Constructor for Dog Class called" << RESET << std::endl;

}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << BLUE <<  "Copy Constructor for Dog Class called" << RESET << std::endl;

}

Dog::~Dog()
{
	delete _brain;
	std::cout << BLUE <<  "Destructor for Dog Class called" << RESET << std::endl;

}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << BLUE <<  "Copy assigment operator for Dog Class called" << RESET << std::endl;
	
	if (this == &rhs)
		return (*this);
	Animal::operator=(rhs); // Copy base class attributes
	delete _brain; // Delete old _brain
	this->_brain = new Brain(*rhs._brain);
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << BLUE << "Woof Woof!!" << RESET << std::endl;
}

std::string	Dog::getType(void) const{return(_type);}
