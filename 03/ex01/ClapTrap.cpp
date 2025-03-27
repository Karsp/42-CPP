/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:46:23 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/14 18:46:27 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name ("Deffie"),
	_hp (10),
	_ep (10),
	_ad (0)
{
	std::cout << AZUL << "Default constructor called." << std::endl;
	std::cout << RESET;
	
}

ClapTrap::ClapTrap(std::string name):_name (name),
	_hp (10),	_ep (10),	_ad (0)
{
	std::cout << AZUL << "Overload constructor called." << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name (other._name),
	_hp (other._hp),	_ep (other._ep),	_ad (other._ad)
{
	std::cout << AZUL << "Copy constructor called." << std::endl;
	std::cout << RESET;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << AZUL << "Copy assignment operator called." << std::endl;
	std::cout << RESET;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << AZUL << "Destructor called." << std::endl;
	std::cout << RESET;

}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no Energy Points left to Attack." << std::endl;
		return ;
	}	
	std::cout << "ClapTrap " << this->_name << " attacks "
	<< target <<", causing " << this->_ad << " points of damage!"
	<< std::endl;
	
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name << " received "
	<< amount <<" points of damage!"
	<< std::endl;
	if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repared." << std::endl;
		return ;
	}	
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no Energy Points left to Be Repaired." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " use Be Repaired to recover "
	<< amount <<" hit points!."	<< std::endl;
	this->_hp += amount;
	--this->_ep;
	std::cout << this->_name << " has " << this->_ep << " EP left." << std::endl;
	std::cout << this->_name << " has " << this->_hp << " HP left." << std::endl;
}

std::string	ClapTrap::getName(void)
{ return (this->_name);}

void	ClapTrap::setName(std::string name)
{ this->_name = name;}

int	ClapTrap::getHP(void)
{ return (this->_hp);}

void	ClapTrap::setHP(int amount)
{ 
	std::cout << "ClapTrap " << this->_name << " set "  << amount << 
	" health points." << std::endl;
	this->_hp = amount;
}
int	ClapTrap::getEP(void)
{ return (this->_ep);}

void	ClapTrap::setEP(int amount)
{ 
	std::cout << "ClapTrap " << this->_name << " set "  << amount << 
	" energy points." << std::endl;
	this->_ep = amount;
}
int	ClapTrap::getAD(void)
{ return (this->_ad);}

void	ClapTrap::setAD(int amount)
{ 
	std::cout << "ClapTrap " << this->_name << " add "  << amount << 
	" points of attack damage." << std::endl;
	this->_ad = amount;
}