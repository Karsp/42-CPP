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
	Fixed(const int nb);
	Fixed(const float fl);

	Fixed (Fixed& other);
	Fixed& operator=(Fixed& rhs);

	float toFloat( void ) const;
	int toInt( void ) const;

	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
