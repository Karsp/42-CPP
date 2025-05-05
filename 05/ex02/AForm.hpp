#ifndef _AFORM_HPP
# define _AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const  _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
public:
	AForm();
	AForm(std::string const &name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(AForm const &copy);

	AForm & operator=(AForm const &rhs);

	std::string const & getName() const;
	int 			getSignGrade() const;
	int 			getExecGrade() const;
	void			beSigned(Bureaucrat &buro);

	// Friend word It allows the operator<< function to access the private and 
	// protected members of the AForm class.
	friend std::ostream& operator<<(std::ostream&, AForm const & other);

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
	
	class AFormAlreadySignedException : public std::exception {
		private:
			std::string _msg;
		public:
			AFormAlreadySignedException();
			virtual ~AFormAlreadySignedException() throw();
			virtual const char* what() const throw();
	};
};

#endif
