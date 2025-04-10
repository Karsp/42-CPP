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

#ifndef _MATERIASOURCE_HPP
# define _MATERIASOURCE_HPP

# define RESET   "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[0;33m" 

# define SOURCES_SIZE 4
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"


class AMateria;
class IMateriaSource;

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria** _sources;
		int		_size;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource& rhs);

		virtual void 		learnMateria(AMateria* newMaterial);
		virtual AMateria* 	createMateria(std::string const & type);
		void 				listKnownMaterias();
};


#endif