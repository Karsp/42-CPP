#include "Fixed.hpp"

// int const Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_val = other.getRawBits();
}

/// @brief The variable name rhs in the operator= function stands for right-hand 
///		side. This is a common convention in programming, particularly in operator overloading, 
///     to represent the object on the right-hand side of the assignment operator (=).
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) 
		this->_val = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->_val = raw;
}
