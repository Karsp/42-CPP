#ifndef _FIXED_HPP
# define _FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_val;
		static int const	_bits = 8;

	public:
	/* Orthodox Canonical Form Requirements */
		/* Constructor */
		Fixed(void);
		/* Overload constructor*/
		Fixed(const int nb);
		Fixed(const float fl);
		/* Copy Constructor */
		Fixed (const Fixed& other);
		/* Destructor */
		~Fixed(void);
	/* Operators Overload */
		/* Copy Assignment Operator */
		Fixed& operator=(const Fixed& rhs);

		/* Comparison Operators */
		bool	operator > (const Fixed& other);
		bool	operator < (const Fixed& other);
		bool	operator >= (const Fixed& other);
		bool	operator <= (const Fixed& other);
		bool	operator == (const Fixed& other);
		bool	operator != (const Fixed& other);
		/* Arithmetic Operators */
		Fixed	operator + (const Fixed& other);
		Fixed	operator - (const Fixed& other);
		Fixed	operator * (const Fixed& other);
		Fixed	operator / (const Fixed& other);

		/* Increment/Decrement Operators */
		Fixed	operator ++ (int);
		Fixed	operator ++ ();
		Fixed	operator -- (int);
		Fixed	operator -- ();

		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	max(const Fixed& a, const Fixed& b);

		float 	toFloat( void ) const;
		int 	toInt( void ) const;

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

		//This is declaring a friend function inside the Fixed class. 
		// It allows the operator<< function to access the private and 
		// protected members of the Fixed class.
		friend std::ostream& operator<<(std::ostream&, const Fixed& other);

};

#endif
