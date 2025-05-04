#ifndef _FORM_HPP
# define _FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const  _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
public:
	Form();
	Form(std::string const &name, int signGrade, int execGrade);
	~Form();
	Form(Form const &copy);

	Form & operator=(Form const &rhs);

	std::string const & getName() const;
	int 			getSignGrade() const;
	int 			getExecGrade() const;
	bool 			isSigned();
	void 			setSignGrade(int const grade) const;
	void 			setExecGrade(int const grade) const;
	void			beSigned(Bureaucrat buro);
	// void			incrementGrade();
	// void			decrementGrade();

	// Friend word It allows the operator<< function to access the private and 
	// protected members of the Form class.
	friend std::ostream& operator<<(std::ostream&, Form const & other);

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
	
	class FormAlreadySignedException : public std::exception {
		private:
			std::string _msg;
		public:
			FormAlreadySignedException();
			virtual ~FormAlreadySignedException() throw();
			virtual const char* what() const throw();
	};
};

#endif
