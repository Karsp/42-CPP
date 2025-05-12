#ifndef _Serializer_HPP
# define _Serializer_HPP

# include <iostream>
# include <limits>
# include <exception>
# include <cstdlib>
# include <limits.h> // for INT_MAX, INT_MIN
# include <iomanip> // for std::fixed and std::setprecision
# include <cfloat>    // for FLT_MAX, FLT_MIN
# include <cerrno> // for errno



class Data; 

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &copy);

		~Serializer();
		Serializer & operator=(Serializer const &rhs);
		
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

		

		class	nonDisplayException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	impossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};



#endif
