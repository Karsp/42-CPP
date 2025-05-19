#include "Serializer.hpp"

int	main()
{
	Data d;
	std::cout << "Original Data object address \t" << &d << std::endl;

	uintptr_t ptr = Serializer::serialize(&d);
	std::cout << "Serialized address: " << ptr << std::endl;

	Data* res = Serializer::deserialize(ptr);
	std::cout << "Deserialized address: \t\t" << res << std::endl;
}
