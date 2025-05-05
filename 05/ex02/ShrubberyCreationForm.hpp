#ifndef _ShrubberyCreationForm_HPP
# define _ShrubberyCreationForm_HPP

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);

};

#endif
