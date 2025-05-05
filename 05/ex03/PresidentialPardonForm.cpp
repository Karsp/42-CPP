#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("Dummy")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm overload constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
:AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout <<  "Copy assigment operator for PresidentialPardonForm Class called" << std::endl;
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::executeForm() const
{
	static const char* zaphod_art =
	"⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠉⠁⠄⠄⠈⠙⠻⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⠟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿\n"
	"⣿⣿⣿⣿⡿⠃⠄⠄⠄⢀⣀⣀⡀⠄⠄⠄⠄⠄⠄⠄⠈⢿\n"
	"⣿⣿⣿⡟⠄⠄⠄⠄⠐⢻⣿⣿⣿⣷⡄⠄⠄⠄⠄⠄⠄⠈\n"
	"⣿⣿⣿⠃⠄⠄⠄⢀⠴⠛⠙⣿⣿⡿⣿⣦⠄⠄⠄⠄⠄⠄\n"
	"⣿⣿⠃⠄⢠⡖⠉⠄⠄⠄⣠⣿⡏⠄⢹⣿⠄⠄⠄⠄⠄⢠\n"
	"⣿⠃⠄⠄⢸⣧⣤⣤⣤⢾⣿⣿⡇⠄⠈⢻⡆⠄⠄⠄⠄⣾\n"
	"⠁⠄⠄⠄⠈⠉⠛⢿⡟⠉⠉⣿⣷⣀⠄⠄⣿⡆⠄⠄⢠⣿\n"
	"⠄⠄⠄⠄⠄⠄⢠⡿⠿⢿⣷⣿⣿⣿⣿⣿⠿⠃⠄⠄⣸⣿\n"
	"⠄⠄⠄⠄⠄⢀⡞⠄⠄⠄⠈⣿⣿⣿⡟⠁⠄⠄⠄⠄⣿⣿\n"
	"⠄⠄⠄⠄⠄⢸⠄⠄⠄⠄⢀⣿⣿⡟⠄⠄⠄⠄⠄⢠⣿⣿\n"
	"⠄⠄⠄⠄⠄⠘⠄⠄⠄⢀⡼⠛⠉⠄⠄⠄⠄⠄⠄⣼⣿⣿\n"
	"⠄⠄⠄⠄⠄⡇⠄⠄⢀⠎⠄⠄⠄⠄Zaphod ⠙⢿⣿\n"
	"⠄⠄⠄⠄⢰⠃⠄⢀⠎⠄⠄Beeblebrox ⠙\n";

	std::cout << zaphod_art << std::endl;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


AForm * PresidentialPardonForm::clone() const
{
	return (new PresidentialPardonForm());
}