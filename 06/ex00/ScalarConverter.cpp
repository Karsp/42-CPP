#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout <<  "Copy assigment operator for ScalarConverter Class called" << std::endl;
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);	
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(std::string &input)
{
	std::cout <<  checkType(input) << std::endl;
}

enum type ScalarConverter::checkType(std::string &input)
{
	if (isChar(input))
		return (CHAR);
	else if (isInt(input))
		return (INT);
	else if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	else if (isPseudoLiteral(input))
		return (PSEUDOLIT);
	else
		return (UNKNOWN);
}

bool ScalarConverter::isChar(std::string &input)
{
	if (input.size() != 1)
		return(false);
	if (!std::isprint(input[0]) || std::isdigit(input[0]))
		return(false);
	return (true);
}

bool ScalarConverter::isInt(std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (i == 0 && input[i] == '-')
			continue;
		else if (!std::isdigit(input[i]))
			return(false);
	}
	return (true);
}

bool ScalarConverter::isFloat(std::string &input)
{
	if (input.size() < 4)
		return false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
			continue;
		else if (i == (input.size() -1) && input[i] == 'f' && std::isdigit(input[i - 1]))
			return (true);
		else if (!std::isdigit(input[i]))
			return(false);
	}
	return (false);
}


bool ScalarConverter::isDouble(std::string &input)
{
	if (input.size() < 3)
		return false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
			continue;
		else if (!std::isdigit(input[i]))
			return(false);
	}
	return (true);
}

bool ScalarConverter::isPseudoLiteral(std::string &input)
{
	std::string pseudoLiterals[] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};

	if (input.size() < 3)
		return false;
	for (size_t i = 0; i < 6; i++)
	{
		if (input == pseudoLiterals[i])
			return (true);
	}
	return (false);
}