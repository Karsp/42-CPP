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
	_size = 0;
	this->_sources = new AMateria*[SOURCES_SIZE];
	for (int i = 0; i < SOURCES_SIZE; i++)
		_sources[i] = NULL;
	std::cout << GREEN << "Default Constructor for MateriaSource Class called." << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// Delete first
	delete[] this->_sources;
	this->_sources = new AMateria*[SOURCES_SIZE];
	for (int i = 0; i < _size; i++)
	{
		this->_sources[i] = other._sources[i]->clone(); //use amateria clone
	}
	this->_size = other._size;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
		return (*this);
	delete[] this->_sources;
	// Delete first
	for (int i = 0; i < _size; i++)
	{
		_sources[i] = rhs._sources[i]->clone();
	}
	_size = rhs._size;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	
	// Delete materias sources

	for (int i = 0; i < _size; i++)
	{
		delete _sources[i];
	}
	delete[] this->_sources;
	std::cout << GREEN << "Destructor for MateriaSource Class called." << RESET << std::endl;

}




void	MateriaSource::learnMateria(AMateria* newMaterial)
{
	if (_size >= 4)
	{
		std::cout << GREEN << "Max Materia source limit reached." << RESET << std::endl;
		return;
	}
	_sources[_size] = newMaterial;
	++_size;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type.compare(_sources[i]->getType().c_str()))
		{
			AMateria* created = new Ice();
			return (created);
		}
	}
	std::cout << GREEN << "No source match this Materia type." << RESET << std::endl;
	return (0);
}