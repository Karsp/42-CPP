#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
	int res = rand();

	if (res % 3 == 0)
		return (new A());
	if (res % 3 == 1)
		return (new B());
	if (res % 3 == 2)
		return (new C());
	return (NULL);
}

void identify(Base* p)
{
	if(dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	else if(dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	else if(dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
	// else 
	// {
	// 	std::cout << "Uknown type." << std::endl;
	// 	return;
	// }
}


void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		;
	}
	
	
}


int	main()
{
	Base * test1;
	Base * test2;
	Base * test3;
	Base * test4;
	Base * test5;


	test1 = generate();
	test2 = generate();
	test3 = generate();
	test4 = generate();
	test5 = generate();
	
	std::cout << "Testing identify * function:" << std::endl;
	identify(test1);
	identify(test2);
	identify(test3);
	identify(test4);
	identify(test5);

	std::cout << "Testing identify & function:" << std::endl;
	identify(*test1);
	identify(*test2);
	identify(*test3);
	identify(*test4);
	identify(*test5);


	delete (test1);
	delete (test2);
	delete (test3);
	delete (test4);
	delete (test5);
}
