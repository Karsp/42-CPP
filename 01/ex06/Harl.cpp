#include "Harl.hpp"

// Color codes (add on header?)
#define RESET   "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[0;33m"

Harl::Harl()
{
}
Harl::Harl(std::string level)
{
	this->filter_complain(level);
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << GREEN;
	std::cout << "<< Debug Message >>" << std::endl;
    std::cout << RESET;

}

void	Harl::info( void )
{
	std::cout << BLUE;
	std::cout << "<< Info Message >>" << std::endl;
    std::cout << RESET;
}

void	Harl::warning( void )
{
		std::cout << YELLOW;
	std::cout << "<< Warning Message >>" << std::endl;
    std::cout << RESET;
}

void	Harl::error( void )
{
	std::cout << RED;
	std::cout << "<< Error Message >>" << std::endl;
    std::cout << RESET;
}

void	Harl::def( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			(this->*ptr[i])();
	}

}
void	Harl::filter_complain(std::string filter)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level = -1;
	void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == filter)
			level=i;
	}

	while (level <= 3)
	{
		switch (level)
		{
		case DEBUG:
			(this->*ptr[level])();
			break;
		case INFO:
			(this->*ptr[level])();
			break;
		case WARNING:
			(this->*ptr[level])();
			break;
		case ERROR:
			(this->*ptr[level])();
			break;
		default:
			this->def();
			return ;
		}
		level++;
	}
}