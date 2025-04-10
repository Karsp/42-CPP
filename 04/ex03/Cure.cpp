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

#include "Cure.hpp"

Cure::Cure():	AMateria("Cure")
{
	std::cout << YELLOW <<  "Default Constructor for Cure Class called" << RESET << std::endl;

}

Cure::Cure(const Cure& other):AMateria(other._type)
{
    std::cout << YELLOW << "Copy Constructor for Cure Class called" << RESET << std::endl;
}

Cure::~Cure()
{
	// delete ;
	std::cout << YELLOW <<  "Destructor for Cure Class called" << RESET << std::endl;

}

Cure& Cure::operator=(const Cure& rhs)
{
	std::cout << YELLOW <<  "Copy assigment operator for Cure Class called" << RESET << std::endl;
	
	if (this == &rhs)
		return (*this);
	// AMateria::operator=(rhs); // Copy base class attributes
	// delete _type; // Delete old _brain
	// this->_type = new Cure(*rhs._type);
	return (*this);
}

std::string const & Cure::getType() const{ return(_type); }

void	Cure::use(ICharacter& target)
{
	std::cout << YELLOW <<  "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}

AMateria* Cure::clone() const { 	return (new Cure()); }