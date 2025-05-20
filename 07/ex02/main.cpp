#include "Array.hpp"

int main() {
	
	try {
		Array<int> b;
		std::cout << "============ LETS CREATE AN EMPTY ARRAY, AND LETS ACCESS IT AT INDEX 0 ================" << std::endl;
		std::cout << b[0] << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout <<  std::endl;
	std::cout << "============ NOW, LETS CREATE A VALID ARRAY, SIZE 5, AND POPULATE IT ================" << std::endl;
	
	Array<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << std::endl;
	
	std::cout <<  std::endl;

	try {
		std::cout << "============ NOW, LETS TRY TO RANDOMLY ACCESS OUR ARRAY AT INDEX -432 ================" << std::endl;
		std::cout << a[-432] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<  std::endl;

	std::cout << "============ FINALLY, LETS CHECK IF IT IS PERFORMING DEEP COPY ================" << std::endl;
	std::cout << "Array<int> a2;" << std::endl;
	Array<int> a2;
	std::cout << "a2 = a;" << std::endl;
	a2 = a;
	std::cout << "a[0] = 127;" << std::endl;
  	a[0] = 127; 

	std::cout <<  std::endl;

	std::cout << "A ELEMENTS: " << std::endl;
	for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << std::endl;
	
	std::cout <<  std::endl;

	std::cout << "A2 ELEMENTS: " << std::endl;
  for (size_t i = 0; i < a2.size(); i++) std::cout << a2[i] << std::endl;
	return 0;
}