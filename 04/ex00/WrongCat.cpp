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


#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Default Constructor for WrongCat Class called" << std::endl;

}

WrongCat::WrongCat(const WrongCat& other)
{
	_type = other._type;
	std::cout << "Copy Constructor for WrongCat Class called" << std::endl;

}

WrongCat::~WrongCat()
{
std::cout << "Destructor for WrongCat Class called" << std::endl;

}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "Copy assigment operator for WrongCat Class called" << std::endl;

	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW << "ROAAAARRRR!!  Coff, coff.." << RESET << std::endl;
}

std::string	WrongCat::getType(void) const{return(_type);}
