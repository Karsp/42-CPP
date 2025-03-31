/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:41:09 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 15:41:10 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ScavTrap("MonsTrap_clap_name"), FragTrap("MonsTrap_clap_name")
{
	this->DiamondTrap::_name = "MonsTrap";
	this->_hp = this->FragTrap::_hp;
	this->_ep = this->ScavTrap::_ep;
	this->_ad = this->FragTrap::_ad;
	this->ClapTrap::_name = "MonsTrap_clap_name";
	std::cout <<  YELLOW << "DiamondTrap " << this->_name << " default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name+ "_clap_name"), FragTrap(name+ "_clap_name")
{
	this->DiamondTrap::_name = name;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
	this->ClapTrap::_name = name + "_clap_name";
	std::cout <<  YELLOW << "DiamondTrap " << this->_name << " Overload default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	this->DiamondTrap::_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
	std::cout <<  YELLOW << "DiamondTrap " << this->_name << " copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this == &rhs)
		return (*this);
	this->DiamondTrap::_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_ad = rhs._ad;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout <<  YELLOW << "DiamondTrap " << this->_name << " destructor called" << RESET << std::endl;

}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->_name 
              << ", but my ClapTrap name is " << this->ClapTrap::_name 
              << "!" << std::endl;
}
