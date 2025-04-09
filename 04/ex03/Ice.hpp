/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:59 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:46:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Brain;

class Ice: public Animal
{
	private:
		std::string const _type;
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();
		Ice& operator=(const Ice& rhs);

		std::string getType() const;
		virtual void	makeSound(void) const;

};

#endif
