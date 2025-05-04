#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
:_name("Another Bureaucrat"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
:_name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
:_name(copy._name)
{
	if (copy._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (copy._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = copy._grade;
	
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		if (rhs._grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (rhs._grade < 1)
			throw Bureaucrat::GradeTooHighException();
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);	
}

Bureaucrat::~Bureaucrat()
{}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string const &Bureaucrat::getName() const
{
	return(_name);
}

void Bureaucrat::incrementGrade()
{
	--_grade;
	if (_grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (_grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	++_grade;
	if (_grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (_grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
}


std::ostream& operator<<(std::ostream &out, Bureaucrat const &other)
{
	out << other._name << ", bureaucrat grade " << other._grade << ".";
	return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	:_msg("Bureaucrat::GradeTooHighException: error: grade too high.") {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	:_msg("Bureaucrat::GradeTooLowException: error: grade too low.") {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}