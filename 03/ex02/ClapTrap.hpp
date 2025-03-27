/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:46:35 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/14 18:46:37 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include<iostream>
# include<iostream>

#define RESET   "\033[0m"
#define AZUL "\033[34m" // Azul
#define VERDE "\033[32m" // Verde
#define ROJO "\033[31m" // Rojo

class ClapTrap
{
	protected:
		std::string _name;
		int		_hp; //hit points
		int		_ep; //energy points
		int		_ad; //attack damage

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& rhs);
	
		void	attack (const std::string& target);
		void	takeDamage (unsigned int amount);
		void	beRepaired (unsigned int amount);
		std::string	getName(void);
		void	setName(std::string name);
		int		getHP(void);
		void	setHP(int amount);
		int		getEP(void);
		void	setEP(int amount);
		int		getAD(void);
		void	setAD(int amount);
};

#endif

