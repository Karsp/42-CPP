/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:09:32 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/07 16:09:33 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GREEN << "Default Constructor for MateriaSource Class called." << RESET << std::endl;
	size = 0;
}

void	MateriaSource::learnMateria(AMateria* newMaterial)
{
	if (size >= 4)
	{
		std::cout << GREEN << "Max Materia source limit reached." << RESET << std::endl;
		return;
	}
	source[size] = newMaterial;
	++size;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (type.compare(source[i]->getType().c_str()))
		{
			AMateria* created = new Ice();
			return (created);
		}
	}
	std::cout << GREEN << "No source match this Materia type." << RESET << std::endl;
	return (0);
}