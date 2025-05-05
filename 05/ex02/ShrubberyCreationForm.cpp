#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm",145,137), _target("Dummy")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm("ShrubberyCreationForm",145,137), _target(target)
{
	std::cout << "ShrubberyCreationForm overload constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
:AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout <<  "Copy assigment operator for ShrubberyCreationForm Class called" << std::endl;
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

