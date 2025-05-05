#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	
	std::cout << "========== ==========" << std::endl;
	std::cout << "Lets start with some basic tests" << std::endl;
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "========== ==========" << "\n" << std::endl;
	
	AForm *f;
	f = new ShrubberyCreationForm("LALA");
	std::cout << *f;

	Bureaucrat b("Carlos", 150);
	std::cout << b << std::endl;

	std::cout << "\n==== Sign Falied ====" << std::endl;
	b.signForm(*f);
	std::cout << "\n==== Executing a not signed form ====" << std::endl;
	b.executeForm(*f);

	std::cout << " " << std::endl;
	
	Bureaucrat b1("Juan", 140);
	std::cout << b1 << std::endl;
	
	std::cout << "\n==== Sign Success ====" << std::endl;
	b1.signForm(*f);
	std::cout << "\n==== Not having enough grade to execute, but enough to sign ====" << std::endl;
	b1.executeForm(*f);
	

	std::cout << "\n==== ====" << std::endl;
	std::cout << "Now lets create a buro that does meet the requirements"<< "\n"  << std::endl;
	
	Bureaucrat b2("Marcos", 5);
	std::cout << b2 << std::endl;
	b2.signForm(*f);
	
	std::cout << "\n==== ====" << std::endl;
	std::cout << "Lets try to execute it"<< "\n"  << std::endl;
	b2.executeForm(*f);
	
	std::cout << "\n==== ====" << std::endl;
	std::cout << "Now lets try another time"<< "\n"  << std::endl;
	b2.executeForm(*f);

	delete f;

	std::cout << " " << std::endl;

	// std::cout << "========== ==========" << std::endl;
	// std::cout << "RobotomyRequestForm" << std::endl;
	// std::cout << "========== ==========" << std::endl;

	// AForm *f2;
	// f2 = new RobotomyRequestForm();
	
	// std::cout << *f2;
	// std::cout << "Lets execute this form a couple of times" << std::endl;
	// b2.signForm(*f2);
	// b2.executeForm(*f2);
	// b2.executeForm(*f2);
	
	// std::cout << "========== ==========" << std::endl;
	// std::cout << "I know, animation are preatty awesome!!" << std::endl;
	// std::cout << "========== ==========" << std::endl;

	// delete f2;

	std::cout << " " << std::endl;

	std::cout << "========== ==========" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "========== ==========" << std::endl;
	
	AForm *f3 = new PresidentialPardonForm();

	std::cout << *f3;
	b.signForm(*f3);
	b.executeForm(*f3);

	delete f3;
	

}
