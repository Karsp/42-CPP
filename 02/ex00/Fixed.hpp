#ifndef _FIXED_HPP
# define _FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					_val;
	static int const	_bits = 8;

public:
/* Orthodox Canonical Form Requirements */
	/* Constructor */
	Fixed(void);
	/* Copy Constructor */
	Fixed (const Fixed& other);
	/* Destructor */
	~Fixed(void);
/* Operators Overload */
	/* Copy Assignment Operator */
	Fixed& operator=(const Fixed& rhs);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
