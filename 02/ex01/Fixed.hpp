#ifndef _FIXED_HPP
# define _FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					_val;
	static int const	_fbits;

public:
	Fixed(/* args */);
	Fixed (Fixed& other);
	Fixed& operator=(Fixed& rhs);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
