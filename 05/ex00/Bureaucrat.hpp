#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	std::string  _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);

	Bureaucrat & operator=(Bureaucrat const &rhs);

	std::string const & getName() const;
	int 			getGrade() const;
	void			incrementGrade();
	void			decrementGrade();

	// It allows the operator<< function to access the private and 
	// protected members of the Bureaucrat class.
	friend std::ostream& operator<<(std::ostream&, Bureaucrat const & other);

	// Exceptions
	class GradeTooHighException: public std::exception
	{
		private:
				std::string  _msg;
		public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		virtual const char * what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
		private:
				std::string  _msg;
		public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		virtual const char * what() const throw();
	};
};

#endif
