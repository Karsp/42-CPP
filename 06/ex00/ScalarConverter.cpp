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
	{
		printPseudoLiteral(input);
	}
	else if (type == UNKNOWN)
		printUnknown();
	else
	{
		printChar(input);
		printInt(input);
		printFloat(input);
		printDouble(input);
	}
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

	if (isChar(input))
		return (static_cast<char>(*input.c_str()));
	nmb = std::atoi(input.c_str());
	if (nmb < 0 || nmb > 127)
		throw impossibleException();
	else if (nmb < 32 || nmb > 126)
		throw nonDisplayException();
	if (input.size() == 1)
		tmp = static_cast<char>(*input.c_str());
	else
		tmp = static_cast<char>(nmb);
	if (tmp == '\0')
		throw impossibleException();
	return (tmp);
}


int ScalarConverter::convertToInt(std::string &input)
{
	long nmb;

	if (isChar(input))
		nmb = static_cast<char>(*input.c_str());
	else
		nmb = std::atol(input.c_str());
	if (nmb > INT_MAX || nmb < INT_MIN)
		throw impossibleException();
	return (static_cast<int>(nmb));
}


float ScalarConverter::convertToFloat(std::string &input)
{
	const char *val = input.c_str();
	char *endptr;
	errno = 0; 
	float nmb;

	if (isChar(input))
	{
		nmb = static_cast<char>(*input.c_str());
		return (nmb);
	}
	else if (input == "0")
		return(0);
	nmb = std::strtof(val, &endptr);

	if (*endptr != '\0' || errno != 0) 
		throw impossibleException();
	if (nmb > FLT_MAX || nmb < FLT_MIN)
		throw impossibleException();
	return (nmb);
}

double ScalarConverter::convertToDouble(std::string &input)
{
	const char *val = input.c_str();
	char *endptr;
	errno = 0;
	double nmb;

	if (isChar(input))
	{
		nmb = static_cast<char>(*input.c_str());
		return (nmb);
	}
	else if (input == "0")
		return(0);
	nmb = std::strtod(val, &endptr);

	if (*endptr != '\0' || errno != 0) 
		throw impossibleException();
	if (nmb > FLT_MAX || nmb < FLT_MIN)
		throw impossibleException();
	return (nmb);
}

void ScalarConverter::printChar(std::string &input)
{
	char tmp;

	std::cout << "char: " ;
	try
	{
		tmp = convertToChar(input);
		std::cout << "'" << tmp << "'" << std::endl;
	}
	catch(const std::exception& e)	
	{
		std::cerr << e.what() << '\n';
	}
}

void ScalarConverter::printInt(std::string &input)
{
	int tmp;

	std::cout << "int: " ;
	try
	{
		tmp = convertToInt(input);
		std::cout << tmp << std::endl;
	}
	catch(const std::exception& e)	
	{
		std::cerr << e.what() << '\n';
	}
}

void ScalarConverter::printFloat(std::string &input)
{
	float tmp;

	std::cout << "float: " ;
	if (isFloat(input))
	{
		std::cout << input << std::endl;
		return;
	}
	try
	{
		tmp = convertToFloat(input);
		std::cout << std::fixed << std::setprecision(1) << tmp << "f" << std::endl;
	}
	catch(const std::exception& e)	
	{
		std::cerr << e.what() << '\n';
	}
}

void ScalarConverter::printDouble(std::string &input)
{
	double tmp;

	std::cout << "double: " ;
	if (isFloat(input))
	{
		std::cout << input.substr(0, (input.size() -1)) << std::endl;
		return;
	}
	try
	{
		tmp = convertToDouble(input);
		std::cout << std::fixed << std::setprecision(1) << tmp << std::endl;
	}
	catch(const std::exception& e)	
	{
		std::cerr << e.what() << '\n';
	}
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

void ScalarConverter::printUnknown()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
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