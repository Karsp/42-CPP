#include "AForm.hpp"


AForm::AForm()
:_name("Another AForm"), _signed(0), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;

}

AForm::AForm(std::string const &name, int signGrade, int execGrade)
:_name(name), _signed(0), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "AForm overload constructor called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	
}

AForm::AForm(AForm const &copy)
:_name(copy.getName()),  _signed(copy._signed),_signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "AForm copy constructor called" << std::endl;

}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);	
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

std::string const &AForm::getName() const
{
	return(_name);
}

void AForm::beSigned(Bureaucrat &buro)
{
	if (buro.getGrade() > _signGrade)
	{
		throw AForm::GradeTooLowException();
	}
	if (this->_signed) {
		std::cout << this->_name << ": AForm is already signed" << std::endl;
		throw AForm::AFormAlreadySignedException();
	}
	else
	{
		_signed = true;
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed)
	{
		if (executor.getGrade() > _execGrade)
			throw AForm::GradeTooLowException();
		std::cout << "Execute" << std::endl;
	}
	else
		throw AForm::AFormNotSignedException();
}



std::ostream& operator<<(std::ostream &out, AForm const &other)
{
	if (other._signed)
		out << "AForm "<< other.getName() << " is signed, Sign grade is " << other.getSignGrade() << " and execution grade is " << other.getExecGrade() << "." << std::endl;
	else
		out << "AForm "<< other.getName() << " is not signed, Sign grade is " << other.getSignGrade() << " and execution grade is " << other.getExecGrade() << "." <<  std::endl;

	return out;
}

AForm::GradeTooHighException::GradeTooHighException()
	:_msg("AForm::GradeTooHighException: error: grade too high.") {}

AForm::GradeTooLowException::GradeTooLowException()
	:_msg("AForm::GradeTooLowException: error: grade too low.") {}

AForm::AFormAlreadySignedException::AFormAlreadySignedException()
	:_msg("AForm::AFormAlreadySignedException: AForm already signed.") {}

AForm::AFormNotSignedException::AFormNotSignedException()
	:_msg("AForm::AFormNotSignedException: AForm is not signed.") {}

const char* AForm::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::AFormAlreadySignedException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::AFormNotSignedException::what() const throw() {
	return this->_msg.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::AFormAlreadySignedException::~AFormAlreadySignedException() throw() {}

AForm::AFormNotSignedException::~AFormNotSignedException() throw() {}
