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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("Some extraordinary random WrongAnimal")
{
	std::cout << "Default Constructor for WrongAnimal Class called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other):_type(other._type)
{
	std::cout << "Copy Constructor for WrongAnimal Class called" << std::endl;

}

WrongAnimal::~WrongAnimal()
{
std::cout << "Destructor for WrongAnimal Class called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "Copy assigment operator for WrongAnimal Class called" << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << YELLOW << "* this Wronganimal makes an strage strage strage strage strage strage sound *" << RESET << std::endl;
}

std::string	WrongAnimal::getType() const {return(_type);}