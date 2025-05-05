#include "RobotomyRequestForm.hpp"
#include <unistd.h> // for usleep

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("Dummy"), _works(0)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target), _works(0)
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

void	RobotomyRequestForm::executeForm() const
{
	animation();
	_works = !_works;
}

void	RobotomyRequestForm::animation() const
{
	// ASCII drilling animation frames
	static const char* drill_frame_1 =
	"**************\n"
	"*****    *****\n"
	"***  **     ***\n"
	"****   ***  ****\n"
	"***    *     ***\n"
	"*****     ******\n"
	"***************\n";

	static const char* drill_frame_2 =
	"*** * * * * * ***\n"
	"**   * * * *   **\n"
	"****   *   ******\n"
	"***  *  *  *  ***\n"
	"** *   ***   * **\n"
	"*** *  * *  * ***\n";

	static const char* drill_frame_3 =
	"**  *  ***  *  **\n"
	"**** *  *  * ****\n"
	"***   *  *  *  ***\n"
	"** *  *** ***  **\n"
	"*****   *   *****\n"
	"**  *  * * *  * **\n"
	"***  **   **  ***\n";

	// ASCII nuclear explosion
	static const char* nuclear_explosion =
	"          _ ._  _ , _ ._\n"
	"        (_ ' ( `  )_  .__)\n"
	"      ( (  (    )   `)  ) _)\n"
	"     (__ (_   (_ . _) _) ,__)\n"
	"         `~~`\\ ' . /`~~`\n"
	"              ;   ;\n"
	"              /   \\\n"
	"_____________/_ __ \\_____________\n";

	static const char* drilling_sound = "*BRRRRRRRRRRRR*";

	const char* frames[] = { drill_frame_1, drill_frame_2, drill_frame_3 };

	// Drilling animation: simulate 6 cycles
	for (int i = 0; i < 6; ++i)
	{
		std::cout << "\033[2J\033[1;1H"; // Clear screen (ANSI escape)
		std::cout << "[ DRILLING... ] " << drilling_sound << std::endl;
		std::cout << frames[i % 3] << std::endl;
		usleep(300000); // 300 ms
	}

	if (_works)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
	{

		std::cout << "\033[2J\033[1;1H"; // Clear screen again
		std::cout << "[ BOOM! 💥 Nuclear explosion ]" << std::endl;
		std::cout << nuclear_explosion << std::endl;
		
		std::cout << "The robotomy has failed." << std::endl;
	}
	usleep(3000000);
}