#include "Form.hpp"


Form::Form()
:_name("Another Form"), _signed(0), _signGrade(150), _execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;

}

Form::Form(std::string const &name, int signGrade, int execGrade)
:_name(name), _signed(0),_signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form overload constructor called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	
}

Form::Form(Form const &copy)
:_name(copy.getName()),  _signed(copy._signed),_signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "Form copy constructor called" << std::endl;

}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);	
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

std::string const &Form::getName() const
{
	return(_name);
}

void Form::beSigned(Bureaucrat &buro)
{
	if (buro.getGrade() > _signGrade)
	{
		throw Form::GradeTooLowException();
	}
	if (this->_signed) {
		std::cout << this->_name << ": form is already signed" << std::endl;
		throw Form::FormAlreadySignedException();
	}
	else
	{
		_signed = true;
	}
}


std::ostream& operator<<(std::ostream &out, Form const &other)
{
	if (other._signed)
		out << "Form "<< other.getName() << " is signed, form sign grade is " << other.getSignGrade() << " and execution grade is " << other.getExecGrade() << "." << std::endl;
	else
		out << "Form "<< other.getName() << " is not signed, form sign grade is " << other.getSignGrade() << " and execution grade is " << other.getExecGrade() << "." <<  std::endl;

	return out;
}

Form::GradeTooHighException::GradeTooHighException()
	:_msg("Form::GradeTooHighException: error: grade too high.") {}

Form::GradeTooLowException::GradeTooLowException()
	:_msg("Form::GradeTooLowException: error: grade too low.") {}

Form::FormAlreadySignedException::FormAlreadySignedException()
	:_msg("Form::FormAlreadySignedException: form already signed.") {}

const char* Form::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* Form::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

const char* Form::FormAlreadySignedException::what() const throw() {
	return this->_msg.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::FormAlreadySignedException::~FormAlreadySignedException() throw() {}
