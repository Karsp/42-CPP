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
	std::cout << RED << "Default Constructor for Cat Class called" << RESET << std::endl;
	_type = "Cat";
	_brain = new Brain();

}

// Initialize on initializer list to prevent double message from brain.
Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) 
{
    std::cout << RED << "Copy Constructor for Cat Class called" << RESET << std::endl;
}
// Cat::Cat(const Cat& other)
// {
// 	std::cout << RED <<  "Copy Constructor for Cat Class called" << RESET << std::endl;
// 	_type = other._type;
// 	_brain = new Brain(*other._brain);
// }

Cat::~Cat()
{
	std::cout << RED <<  "Destructor for Cat Class called" << RESET << std::endl;
	delete _brain;

}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << RED <<  "Copy assigment operator for Cat Class called" << RESET << std::endl;

	if (this == &rhs)
		return (*this);
	Animal::operator=(rhs);
	delete _brain;
	this->_brain = new Brain(*rhs._brain);
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << RED << "Meow Meow!!" << RESET << std::endl;
}

std::string	Cat::getType(void) const{return(_type);}
