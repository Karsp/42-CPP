/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:03:16 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/17 14:03:18 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Scavei")
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout <<  ROJO << "ScavTrap " << this->_name << " default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << ROJO << "ScavTrap " << this->_name << " overload constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)	
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
	std::cout <<  ROJO << "ScavTrap " << this->_name << " copy constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << ROJO << "ScavTrap " << this->_name << " Destructor called." << std::endl;
	std::cout << RESET;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " is now in Gate keeper mode." << std::endl;
}


void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack cause is dead." << std::endl;
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no Energy Points left to Attack." << std::endl;
		return ;
	}	
	std::cout << "ScavTrap " << this->_name << " attacks "
	<< target <<", causing " << this->_ad << " points of damage!"
	<< std::endl;
	
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
}
