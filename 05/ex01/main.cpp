#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form f("Form1", 20, 10);

	std::cout << f;

	std::cout << "\n==== ====" << std::endl;
	std::cout << "Lets create a Buro that doesnt meet the requirements"<< "\n"  <<  std::endl;

	Bureaucrat b("carlos", 70);
	std::cout << b << std::endl;
	b.signForm(f);
	std::cout << "\n==== ====" << std::endl;
	std::cout << "That was expected" << std::endl;
	std::cout << "Now lets create a buro that does meet the requirements"<< "\n"  << std::endl;
	
	Bureaucrat b2("carlos", 5);
	std::cout << b2 << std::endl;
	b2.signForm(f);
	std::cout << f.getName() << ": isSigned(): " << f.isSigned() << std::endl;
	std::cout << "\n==== ====" << std::endl;
	std::cout << "Now lets create invalid forms"<< "\n"  << std::endl;

	try {
		Form f2("Form2", -24, 10);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f2("Form3", 10, -4);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f2("Form4", 150, 151);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f2("Form5", 151, 10);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n==== ====" << std::endl;
	std::cout << "Last, but not least, lets sign a form three times" << "\n" << std::endl;

	Form form("lastForm", 100, 100);
	b.signForm(form);
	b.signForm(form);
	b.signForm(form);
}
