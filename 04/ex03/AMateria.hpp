/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:09:25 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/07 16:09:26 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERRIA_HPP
# define AMATERRIA_HPP

# define RESET   "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[0;33m" 

# define EQUIPPED 1
# define UNEQUIPPED 0


# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:
		std::string const _type;
		bool	_state;

    public:
		AMateria();
		AMateria(std::string const & type);
		virtual		~AMateria();
		AMateria(const AMateria& other);
		AMateria& 	operator=(const AMateria& rhs);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);

		bool	getState();
		void	setState(bool state);

};


#endif