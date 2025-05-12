#include "Serializer.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments." << std::endl;
		return (0);
	}
	std::string input = argv[1];
	ScalarConverter::convert(input);
	return (0);

}