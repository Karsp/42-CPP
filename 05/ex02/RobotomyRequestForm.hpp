#ifndef _RobotomyRequestForm_HPP
# define _RobotomyRequestForm_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &copy);

	RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);

};

#endif
