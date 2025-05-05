#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout <<  "Copy assigment operator for Intern Class called" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);	
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	static const std::string _formList[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	size_t id = -1;

	for (size_t i = 0; i < _formList->size(); i++)
	{
		if (!formName.compare(_formList[i]))
		{
			id = i;
			break;
		}
	}
	

	switch (id)
	{
	case SHRUBBERY:
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (new ShrubberyCreationForm(target));
	
	case ROBOTOMY:
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (new RobotomyRequestForm(target));
	
	case PRESIDENTIAL:
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (new PresidentialPardonForm(target));
	
	default:
		std::cout << "Stupid Intern, stupid!!!! I only ask you a single thing, create a form named " << formName << "!" << std::endl;
		return (NULL);
	}
}