/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:44 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 15:23:46 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	~FragTrap();
	FragTrap& operator=(const FragTrap& rhs);

	void	highFivesGuys(void);
};


#endif

