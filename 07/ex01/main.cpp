#include <cstddef>
#include "iter.hpp"

template <typename T> 
void increment1(T &n) 
{
	++n;
}

template <typename T> 
void print(T &n) 
{
  std::cout << n << " ";
}

int main() {
	int arr[4] = {1, 2, 3, 4};
	char charr[4] = {'a', 'G', '!', '4'};

	std::cout << "=======================================================================" << std::endl;
	std::cout << "A basic test, print each value of an array of 4 integers" << std::endl;
	std::cout << "=======================================================================" << std::endl;
	iter(arr, 4, &print);
	std::cout << std::endl;
	
	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now simple change on elements, increment 1 on each element" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	iter(arr, 4, &increment1);
	iter(arr, 4, &print);
	std::cout << std::endl;


	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now lets try some errors, pass a null pointer" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	iter((int*)NULL, 100, &increment1);

	std::cout << "(no crash)" << std::endl;

	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now, lets try another type of elements. Try with an array of chars" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	std::cout << "<<< Before >>>" << std::endl;
	iter(charr, 4, &print);
	std::cout << std::endl;

	std::cout << "<<< After >>>" << std::endl;
	iter(charr, 4, &increment1);
	iter(charr, 4, &print);
	std::cout << std::endl;

}