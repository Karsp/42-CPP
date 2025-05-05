#ifndef _Intern_HPP
# define _Intern_HPP

# include <iostream>
# include "AForm.hpp"

enum forms
{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL
};

class AForm;

class Intern
{
	private:
	public:
		Intern();
		~Intern();
		Intern(Intern const &copy);

		Intern & operator=(Intern const &rhs);

		AForm *makeForm(std::string const &formName, std::string const &target);

};



#endif
