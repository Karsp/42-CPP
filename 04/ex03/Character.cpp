#include "Character.hpp"

Character::Character():_name("My Character"),_size(0)
{
	this->_bag = new AMateria*[BAG_SIZE];
	for (int i = 0; i < BAG_SIZE; i++)
	{
		_bag[i] = NULL;
	}
	std::cout << GREEN << "Default Constructor for Character Class called." << RESET << std::endl;
}

Character::Character(const std::string name): _name(name),_size(0)
{
	this->_bag = new AMateria*[BAG_SIZE];
	for (int i = 0; i < BAG_SIZE; i++)
	{
		_bag[i] = NULL;
	}
	std::cout << GREEN << "Overload Constructor for Character Class called." << RESET << std::endl;

}

Character::~Character()
{
	
	// Delete materias bag
	for (int i = 0; i < _size; i++)
	{
		delete _bag[i];
	}
	delete[] _bag;



	// check map
	// if the materia is equipped to another character?
	// 	for (int i = 0; i < _dropped_bag.size; i++)

	// 		delete _dropped_bag[i];
	// 	}
	// delete[] _dropped_bag;

	// delete _dropped_bag;



	std::cout << GREEN << "Destructor for Character Class called." << RESET << std::endl;

}

Character::Character(const Character& other):_name(other._name)
{
	// Delete first
	delete this->_bag;
	this->_bag = new AMateria*[BAG_SIZE];
	for (int i = 0; i < BAG_SIZE; i++)
	{
		this->_bag[i] = other._bag[i]->clone(); //use amateria clone
	}
	this->_size = other._size;
}
Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
		return (*this);
	_name = rhs.getName();
	// Delete first
	delete this->_bag;
	for (int i = 0; i < BAG_SIZE; i++)
	{
		_bag[i] = rhs._bag[i]->clone();
	}
	_size = rhs._size;
	return (*this);
}

std::string const &Character::getName()const { return(this->_name);}

void	Character::equip(AMateria* m)
{
	if (_size < BAG_SIZE)
	{
		if (!_bag[_size])
		{
			if (m->getState() == EQUIPPED) 
			{
				std::cout << RED << "Cannot equip materia (materia already equipped)" << RESET << std::endl;
				return;
			}
		_bag[_size] = m;
		m->setState(EQUIPPED);
		++_size;
		std::cout << GREEN << this->_name << " equiped new " << m->getType() << RESET << std::endl;
		return;
		}
	}
	std::cout << RED << "Max Materia bag limit reached." << RESET << std::endl;

}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= BAG_SIZE)
		std::cout << RED << "Invalid index for Materia bag." << RESET << std::endl;
	if (idx < _size && _bag[idx])
	{
		std::string materia = _bag[idx]->getType();
		_bag[idx]->setState(UNEQUIPPED);
		_bag[idx] = NULL;
		--_size;
		std::cout << GREEN << this->_name << " unequiped " << materia << RESET << std::endl;
		return;
	}
	std::cout << RED << "Index not found on Materia bag." << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target) // working on this
{
	if (idx < 0 || idx >= BAG_SIZE)
		std::cout << RED << "Can't use that slot. Invalid index." << RESET << std::endl;
	else if (_bag[idx])
		_bag[idx]->use(target);
	else
		std::cout << RED << "No materia on this slot." << RESET << std::endl;
}