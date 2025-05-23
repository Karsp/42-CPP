/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:09:32 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/07 16:09:33 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"

AMateria::AMateria():_type("None")
{
	std::cout << GREEN << "Default Constructor for AMateria Class called" << RESET << std::endl;

}

AMateria::AMateria(std::string const &type):_type(type)
{
	std::cout << GREEN << "Overload Constructor for AMateria Class called" << RESET << std::endl;

}

AMateria::AMateria(const AMateria& other):_type(other._type)
{
	std::cout << GREEN << "Copy Constructor for AMateria Class called" << RESET << std::endl;

}

AMateria::~AMateria()
{
	std::cout << GREEN << "Destructor for AMateria Class called" << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	std::cout << GREEN << "Copy assigment operator for AMateria Class called" << RESET << std::endl;

	(void)rhs;
	return (*this);
}

std::string const & AMateria::getType() const { return(this->_type);}

void	AMateria::use(ICharacter &target)
{
	// (void)target;
	// target.use();
	std::cout << GREEN << "A non materia used by " << target.getName() << RESET << std::endl;
	
}

bool AMateria::getState() const { return(this->_state);}

void AMateria::setState(bool state) { this->_state = state;}
