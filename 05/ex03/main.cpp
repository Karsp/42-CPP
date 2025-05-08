#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
	Intern intern;

	std::cout << "========== ==========" << std::endl;
	std::cout << "Lets create a Intern and do some invalid tests" << std::endl;
	std::cout << "========== ==========" << "\n" << std::endl;
	
	AForm* f4 = intern.makeForm("robotomy creation", "Ups");
	(void)f4;
	std::cout << " " << std::endl;
	
	AForm* f5 = intern.makeForm("ambiguous and infinite strange form", "Never works");
	(void)f5;
	std::cout << " " << std::endl;


	std::cout << "========== ==========" << std::endl;
	std::cout << "Okay, now we can do things well" << std::endl;
	std::cout << "========== ==========" << "\n" << std::endl;


	AForm* f = intern.makeForm("robotomy request", "carlos");
	std::cout << *f;

	std::cout << " " << std::endl;

	AForm* f2 = intern.makeForm("shrubbery creation", "carlos");
	std::cout << *f2;

	std::cout << " " << std::endl;

	AForm* f3 = intern.makeForm("presidential pardon", "carlos");
	std::cout << *f3;

	std::cout << " " << std::endl;

	Bureaucrat b("Carlos", 150);
	std::cout << b << std::endl;

	std::cout << "\n==== Sign Falied ====" << std::endl;
	b.signForm(*f3);
	std::cout << "\n==== Executing a not signed form ====" << std::endl;
	b.executeForm(*f3);

	std::cout << " " << std::endl;
	
	Bureaucrat b1("Juan", 10);
	std::cout << b1 << std::endl;
	
	std::cout << "\n==== Sign Success ====" << std::endl;
	b1.signForm(*f3);
	std::cout << "\n==== Not having enough grade to execute, but enough to sign ====" << std::endl;
	b1.executeForm(*f3);

	std::cout << "\n==== Sign and Excecution success ====" << std::endl;
	b1.signForm(*f2);
	b1.executeForm(*f2);


	std::cout << " " << std::endl;

	delete f;
	delete f2;
	delete f3;


}
