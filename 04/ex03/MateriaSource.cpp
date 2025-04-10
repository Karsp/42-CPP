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
	*this = other;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
		return (*this);
	for (int i = 0; i < _size; i++)
		delete this->_sources[i];
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
	for (int i = 0; i < SOURCES_SIZE; i++)
	{
		if (_sources[i])
			delete _sources[i];
	}
	delete[] this->_sources;
	std::cout << GREEN << "Destructor for MateriaSource Class called." << RESET << std::endl;

}




void	MateriaSource::learnMateria(AMateria* newMaterial)
{
	if (_size >= SOURCES_SIZE)
	{
		std::cout << GREEN << "Max Materia source limit reached." << RESET << std::endl;
		return;
	}
	_sources[_size] = newMaterial;
	++_size;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SOURCES_SIZE; i++)
	{
		if (type.compare(_sources[i]->getType().c_str()))
		{
			if (type.compare("ice"))
				return (new Ice());
			else if (type.compare("cure"))
				return (new Cure());
			else
				break;
		}
	}
	std::cout << GREEN << "No source match this Materia type." << RESET << std::endl;
	return (0);
}

void MateriaSource::listKnownMaterias()
{
	for (int i = 0; i < SOURCES_SIZE; i++)
	{
		if (this->_sources[i])
			std::cout << "- " << this->_sources[i]->getType() << std::endl;
	}
}