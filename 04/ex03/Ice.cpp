/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:51 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:45:52 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():	_type("Ice")
{
	std::cout << BLUE <<  "Default Constructor for Ice Class called" << RESET << std::endl;

}

Ice::Ice(const Ice& other):	_type("Ice")
{
    std::cout << BLUE << "Copy Constructor for Ice Class called" << RESET << std::endl;
}

Ice::~Ice()
{
	// delete _brain;
	std::cout << BLUE <<  "Destructor for Ice Class called" << RESET << std::endl;

}

Ice& Ice::operator=(const Ice& rhs)
{
	std::cout << BLUE <<  "Copy assigment operator for Ice Class called" << RESET << std::endl;
	
	if (this == &rhs)
		return (*this);
	// Animal::operator=(rhs); // Copy base class attributes
	// delete _brain; // Delete old _brain
	// this->_brain = new Brain(*rhs._brain);
	// this->_type = rhs._type;
	// return (*this);
}

std::string	Ice::getType(void) const{return(_type);}
