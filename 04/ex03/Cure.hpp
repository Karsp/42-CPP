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

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	private:
		// std::string const _type;

	public:
		Cure();
		// Cure(std::string const _type);
		Cure(const Cure& other);
		~Cure();
		Cure& operator=(const Cure& rhs);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria
		* 		clone() const;
		virtual void 		use(ICharacter& target);

};

#endif
