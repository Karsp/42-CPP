#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_val = other.getRawBits();
}

/// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) 
		this->_val = rhs.getRawBits();
	return (*this);
}

// int overload constructor
Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb * (1 << _bits));
}

// float overload constructor
Fixed::Fixed(const float fl)
{
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(fl * (1 << _bits))));
}


Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}



//functions

int Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->_val = raw;
}

float	Fixed::toFloat( void) const
{
	return (static_cast<float>(this->_val) / (1 << this->_bits));
}

int Fixed::toInt( void  ) const 
{
	return (this->_val >> this->_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return out;
}

// Comparison Operators

bool	Fixed::operator>(const Fixed& other)
{
	if (this->_val > other._val)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other)
{
	if (this->_val < other._val)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other)
{
	if (this->_val >= other._val)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other)
{
	if (this->_val <= other._val)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other)
{
	if (this->_val == other._val)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other)
{
	if (this->_val != other._val)
		return (true);
	return (false);
}

// Operator Overloading for Arithmetic

Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed	tmp(this->toFloat() + other.toFloat());

	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed	tmp(this->toFloat() - other.toFloat());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed	tmp(this->toFloat() * other.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	if (other._val == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
	}
	Fixed	tmp(this->toFloat() / other.toFloat());
	return (tmp);
}

// Pre-increment: ++obj (Increment first, return reference to updated object)
Fixed Fixed::operator ++ () 
{
    this->_val += 1;
    return *this;
}

// Post-increment: obj++ (Return old object, then increment)
// Return the original (unchanged) object
Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    this->_val += 1;
    return temp;
}

// Pre-decrement: --obj (Increment first, return reference to updated object)
Fixed Fixed::operator -- () 
{
    this->_val -= 1;
    return *this;
}

// Post-decrement: obj-- (Return old object, then increment)
// Return the original (unchanged) object
Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    this->_val -= 1;
    return temp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a._val < b._val)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._val < b._val)
		return ((Fixed&)a);
	else
		return ((Fixed&)b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) 
{
    if (a._val > b._val)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(const Fixed &a, const Fixed &b) 
{
    if (a._val > b._val)
		return ((Fixed&)a);
	else
		return ((Fixed&)b);
}