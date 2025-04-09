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

Ice::Ice():	_type("ice")
{
	std::cout << BLUE <<  "Default Constructor for Ice Class called" << RESET << std::endl;

}

Ice::Ice(const Ice& other):_type(other._type)
{
    std::cout << BLUE << "Copy Constructor for Ice Class called" << RESET << std::endl;
}

Ice::~Ice()
{
	// delete ;
	std::cout << BLUE <<  "Destructor for Ice Class called" << RESET << std::endl;

}

Ice& Ice::operator=(const Ice& rhs)
{
	std::cout << BLUE <<  "Copy assigment operator for Ice Class called" << RESET << std::endl;
	
	if (this == &rhs)
		return (*this);
	// AMateria::operator=(rhs); // Copy base class attributes
	// delete _type; // Delete old _brain
	// this->_type = new Ice(*rhs._type);
	// return (*this);
}

std::string const & Ice::getType() const{return(_type);}

void	Ice::use(ICharacter& target)
{
	std::cout << BLUE <<  "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
