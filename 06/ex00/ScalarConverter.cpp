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
	int type = checkType(input);

	if (type == PSEUDOLIT)
		printPseudoLiteral(input);
		 
	printChar(input);
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

char ScalarConverter::convertToChar(std::string &input)
{
	char tmp;
	int nmb ;

	nmb = std::atoi(input.c_str());
	// std::cout << "nmb " << nmb << std::endl;
	if (!isprint(nmb) && !isascii(nmb))
		throw nonDisplayException();
	if (input.size() == 1)
		tmp = static_cast<char>(*input.c_str());
	else
		tmp = static_cast<char>(nmb);
	// std::cout << "tmp " << tmp << std::endl;
	if (tmp == '\0')
		throw impossibleException();
	return (tmp);
}

void ScalarConverter::printChar(std::string &input)
{
	char tmp;

	std::cout << "char: " ;
	try
	{
		tmp = convertToChar(input);
		std::cout << tmp << std::endl;

	}
	catch(const std::exception& e)	
	{
		std::cerr << e.what() << '\n';
	}
	// std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	// std::cout << "float: " << static_cast<float>(tmp) << ".0f" << std::endl;
	// std::cout << "double: " << static_cast<int>(tmp) << ".0" << std::endl;
}

void ScalarConverter::printPseudoLiteral(std::string &input)
{
	std::string pseudoLiterals[] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};
	size_t idx = 0;
	
	for (size_t i = 0; i < 6; i++)
	{
		if (input == pseudoLiterals[i])
		{
			idx = i;
			break;
		}
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << pseudoLiterals[idx] << "f" << std::endl;
	std::cout << "double: " << pseudoLiterals[idx] << std::endl;
}

const char* ScalarConverter::nonDisplayException::what() const throw()
{
	const char *tmp = "Non displayable";
	return (tmp);
}

const char* ScalarConverter::impossibleException::what() const throw()
{
	const char *tmp = "impossible";
	return (tmp);
}