#include "Character.hpp"

Character::Character():_name("Name"),_size(0)
{
	

}

Character::Character(const std::string name): _name(name),_size(0)
{

}

Character::~Character()
{
	// Delete materias bag
}

Character::Character(const Character& other):_name(other._name)
{
	// Delete first
	for (size_t i = 0; i < _size; i++)
	{
		_bag[i] = other._bag[i];
	}
	_size = other._size;
}
Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
		return (*this);
	_name = rhs.getName();
	// Delete first
	for (size_t i = 0; i < _size; i++)
	{
		_bag[i] = rhs._bag[i];
	}
	_size = rhs._size;
	return (*this);
}

std::string const &Character::getName()const { return(this->_name);}

void	Character::equip(AMateria* m)
{
	if (_size < 4)
	{
		_bag[_size] = m;
		++_size;
		std::cout << GREEN << this->_name << " equiped new " << m->getType() << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "Max Materia bag limit reached." << RESET << std::endl;

}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= _size && _bag[idx])
	{
		std::string materia = _bag[idx]->getType();
		_dropped_bag[_name] = _bag[idx];
		_bag[idx] = NULL;
		--_size;
		std::cout << GREEN << this->_name << " unequiped " << materia << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "Index not found on Materia bag." << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target) // working on this
{
	if (idx >= 0 && idx <= _size && _bag[idx])
	{
		std::string materia = _bag[idx]->getType();
		_dropped_bag[_name] = _bag[idx];
		_bag[idx] = NULL;
		--_size;
		std::cout << GREEN << this->_name << " unequiped " << materia << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "Index not found on Materia bag." << RESET << std::endl;
}