#include "Bureaucrat.hpp"

int main() {
	std::cout << "\n========== ==========" << std::endl;
	Bureaucrat b("Charly", 5);

	for (int i = 0; i <  6; i++) {
		std::cout << b << std::endl;
		try {
			b.incrementGrade();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n========== ==========" << std::endl;

	for (int i = 0; i < 149; i++) 
	{
		std::cout << b << std::endl;
		try 
		{
			b.decrementGrade();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n========== ==========" << std::endl;
	std::cout << "Now lets try to construct the buro with invalid values" << std::endl;
	try {
		int grade = -5;
		std::cout << "grade: " << grade << std::endl;
		Bureaucrat b("Ana", grade);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "========== ==========" << std::endl;
	try {
		int grade = 1000;
		std::cout << "grade: " << grade << std::endl;
		Bureaucrat b("Ana", grade);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

}