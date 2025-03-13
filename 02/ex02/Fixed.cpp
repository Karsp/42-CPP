#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_val = other.getRawBits();
}

/// @brief Copy assignment operator
// The variable name rhs in the operator= function stands for right-hand 
///		side. This is a common convention in programming, particularly in operator overloading, to represent the object on the right-hand side of the assignment operator (=).
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) 
		this->_val = rhs.getRawBits();
	return (*this);
}

// int overload constructor
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb * (1 << _bits));
}

// float overload constructor
//Round f is allowed in this excercise
Fixed::Fixed(const float fl)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(fl * (1 << _bits))));
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//functions

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->_val = raw;
}

/// (1 << 8 equals 256) so it can also handle dividing to 256.
float	Fixed::toFloat( void) const
{
	return (static_cast<float>(this->_val) / (1 << this->_bits));
}

// Right shift reduces the magnitude by dividing by a power of two
int Fixed::toInt( void  ) const 
{
	return (this->_val >> this->_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return out;
}
