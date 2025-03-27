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


DiamondTrap::DiamondTrap(): ClapTrap("MonsTrap_clap_name"), ScavTrap(), FragTrap()
{
	this->DiamondTrap::_name = "MonsTrap";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
	this->ClapTrap::_name = "MonsTrap_clap_name";
	std::cout <<  YELLOW << "DiamondTrap " << this->_name << " default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->DiamondTrap::_name = name;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
	this->ClapTrap::_name = name + "_clap_name";
	std::cout <<  YELLOW << "DiamondTrap " << this->_name << " default constructor called" << RESET << std::endl;
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


void	DiamondTrap::attack(const std::string& target)
{
	if (this->_ep == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " has no Energy Points left to Attack." << std::endl;
		return ;
	}	
	std::cout << "DiamondTrap " << this->_name << " attacks "
	<< target <<", causing " << this->_ad << " points of damage!"
	<< std::endl;
	
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
}


void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "DiamondTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << "DiamondTrap " << this->_name << " received "
	<< amount <<" points of damage!"
	<< std::endl;
	if (this->_hp <= 0)
		std::cout << "DiamondTrap " << this->_name << " is dead." << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "DiamondTrap " << this->_name << " is dead and cannot be repared." << std::endl;
		return ;
	}	
	if (this->_ep == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " has no Energy Points left to Be Repaired." << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->_name << " use Be Repaired to recover "
	<< amount <<" hit points!."	<< std::endl;
	this->_hp += amount;
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
	std::cout << this->_name << " has " << this->_hp << " HP left." << std::endl;
}