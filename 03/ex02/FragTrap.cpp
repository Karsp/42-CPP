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

FragTrap::FragTrap()
{
	this->_name = "Fragui";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout <<  VERDE << "FragTrap " << this->_name << " default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name)
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
	std::cout << "🔥 High-five time! If you're ready to celebrate success, give me a virtual high-five! ✋🙌" << std::endl;
}


void	FragTrap::attack(const std::string& target)
{
	if (this->_ep == 0)
	{
		std::cout << "FragTrap " << this->_name << " has no Energy Points left to Attack." << std::endl;
		return ;
	}	
	std::cout << "FragTrap " << this->_name << " attacks "
	<< target <<", causing " << this->_ad << " points of damage!"
	<< std::endl;
	
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
}


void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << "FragTrap " << this->_name << " received "
	<< amount <<" points of damage!"
	<< std::endl;
	if (this->_hp <= 0)
		std::cout << "FragTrap " << this->_name << " is dead." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead and cannot be repared." << std::endl;
		return ;
	}	
	if (this->_ep == 0)
	{
		std::cout << "FragTrap " << this->_name << " has no Energy Points left to Be Repaired." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " use Be Repaired to recover "
	<< amount <<" hit points!."	<< std::endl;
	this->_hp += amount;
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
	std::cout << this->_name << " has " << this->_hp << " HP left." << std::endl;
}