#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	AForm *f;
	f = new ShrubberyCreationForm();

	std::cout << *f;

	std::cout << "\n==== ====" << std::endl;
	std::cout << "Lets create a Buro that doesn't meet the requirements"<< "\n"  <<  std::endl;

	Bureaucrat b("Carlos", 150);
	std::cout << b << std::endl;
	b.signForm(*f);
	std::cout << "\n==== ====" << std::endl;
	std::cout << "Now lets create a buro that does meet the requirements"<< "\n"  << std::endl;
	
	Bureaucrat b2("Marcos", 5);
	std::cout << b2 << std::endl;
	b2.signForm(*f);
	std::cout << *f;
	
	
	std::cout << "\n==== ====" << std::endl;
	std::cout << "Lets try to execute it"<< "\n"  << std::endl;
	b2.executeForm(*f);
	std::cout << *f;

	// std::cout << "\n==== ====" << std::endl;
	// std::cout << "Now lets create invalid forms"<< "\n"  << std::endl;

	// try {
	// 	AForm f2("Form2", -24, 10);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// 	AForm f2("Form3", 10, -4);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try {
	// 	AForm f2("Form4", 150, 151);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try {
	// 	AForm f2("Form5", 151, 10);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << "\n==== ====" << std::endl;
	// std::cout << "Last, but not least, lets sign a form three times" << "\n" << std::endl;

	// AForm form("lastForm", 100, 100);
	// b.signForm(form);
	// b.signForm(form);
	// b.signForm(form);

	delete f;
}
