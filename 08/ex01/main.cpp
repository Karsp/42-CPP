
#include <string>
#include <iostream>
#include <list>
#include "Span.hpp"


int main()
{
	Span sp3 = Span(5);
	Span sp2 = Span(5);
	Span sp1 = Span(5);
	Span sp = Span(5);
	
	std::cout << "<<< Create and add elements to the Span sp >>>" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "<<< Span sp >>>" << std::endl;
	sp.printSpan();

	std::cout <<  std::endl;

	std::cout << "<<< Shortest Span >>>" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	
	std::cout << "<<< Longest Span >>>" << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout <<  std::endl;
	
	try
	{
		std::cout << "<<< Try to add more elements than size on sp2 >>>" << std::endl;
		sp2.addNumber(6);
		sp2.addNumber(6);
		sp2.addNumber(6);
		sp2.addNumber(6);
		sp2.addNumber(6);
		sp2.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout <<  std::endl;
	}

	
	int arr[] = {71, 12, 32};
	int *first = arr;
	int *last = arr + 3;
	
	std::cout << "<<< Add elements from Array to Span sp1 >>>" << std::endl;
	sp1.addNumber(first, last);
	
	std::cout << "<<< Span sp1 >>>" << std::endl;
	sp1.printSpan();

	std::cout <<  std::endl;
	
	try
	{
		int arr2[] = {71, 12, 32,71, 12, 32};
		int *first = arr2;
		int *last = arr2 + 6;
		
		std::cout << "<<< Now try to add more elements than size from Array to Span sp1 >>>" << std::endl;
		sp1.addNumber(first, last);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout <<  std::endl;
	}
	

	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	std::vector<int>::iterator it1 = v.begin();
	std::vector<int>::iterator it2 = v.end();
	
	std::cout << "<<< Add elements from Vector to Span sp3 >>>" << std::endl;
	sp3.addNumber(it1, it2);
	
	std::cout << "<<< Span sp3 >>>" << std::endl;
	sp3.printSpan();

	std::cout <<  std::endl;


	return 0;
}