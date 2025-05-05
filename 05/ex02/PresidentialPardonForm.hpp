#ifndef _PresidentialPardonForm_HPP
# define _PresidentialPardonForm_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &copy);

	PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);

	void	executeForm() const;

};

#endif
