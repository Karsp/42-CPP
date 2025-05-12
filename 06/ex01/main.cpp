#include "Serializer.hpp"

int	main()
{
	Data	hello;

	// hello.a1= 777;
	// hello.a2= -85;
	// hello.a3= 25;

	Data	*adeu = Serializer::deserialize(Serializer::serialize(&hello));
	// std::cout << adeu->a1 << std::endl << adeu->a2 << std::endl << "hello:" << hello.a3 << std::endl;
}
