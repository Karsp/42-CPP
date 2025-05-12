#ifndef _Serializer_HPP
# define _Serializer_HPP

# include <iostream>

typedef struct {
	char* ptr;
	uintptr_t raw;
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
