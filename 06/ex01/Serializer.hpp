#ifndef _Serializer_HPP
# define _Serializer_HPP

# include <iostream>
# include <stdint.h>

typedef struct {
	char* value;
}	Data;

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
};



#endif
