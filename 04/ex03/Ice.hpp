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

# include "AMateria.hpp"

class Ice: public AMateria
{
	private:
		// std::string const _type;

	public:
		Ice();
		// Ice(std::string const _type);
		Ice(const Ice& other);
		~Ice();
		Ice& operator=(const Ice& rhs);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* 		clone() const;
		virtual void 		use(ICharacter& target);

};

#endif
