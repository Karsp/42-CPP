
#include <string>
#include <iostream>
#include <list>
#include "easyfind.hpp"

int	main()
{
	std::list<int>	l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	std::list<int>::iterator i = l.begin();

	std::cout << *i << std::endl;
	std::cout << *(easyFind(l, 4)) << std::endl;
	try
	{
		std::cout << *(easyFind(l, 10)) << std::endl;
	}
	catch (const std::exception& e) 
	{
        	std::cerr << e.what() << std::endl;
	}
	return (0);
}
