/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:33 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 15:23:35 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Fragui")
{
	this->_name = "Fragui";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout <<  VERDE << "FragTrap " << this->_name << " default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap()
{
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << VERDE << "FragTrap " << this->_name << " overload constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)	
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
	std::cout <<  VERDE << "FragTrap " << this->_name << " copy constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << VERDE << "FragTrap " << this->_name << " Destructor called." << std::endl;
	std::cout << RESET;

}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_ad = rhs._ad;
	return (*this);
}


void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " High-five time! Give me a virtual high-five! ✋🙌" << std::endl;
}

