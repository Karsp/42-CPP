
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

	std::cout << "<<<<<<<< Print first element >>>>>>>>>" << std::endl;
	std::cout << *i << std::endl;
	std::cout << std::endl;

	std::cout << "<<<<<<<< Try to find key 4 >>>>>>>>>" << std::endl;
	std::cout << *(easyfind(l, 4)) << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << "<<<<<<<< Try to find key 10 >>>>>>>>>" << std::endl;
		std::cout << *(easyfind(l, 10)) << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception& e) 
	{
        	std::cerr << e.what() << std::endl;
	}
	return (0);
}
