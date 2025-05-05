#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("Dummy")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm overload constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
:AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout <<  "Copy assigment operator for RobotomyRequestForm Class called" << std::endl;
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

