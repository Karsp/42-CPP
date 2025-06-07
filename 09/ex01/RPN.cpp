/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:09:25 by daviles-          #+#    #+#             */
/*   Updated: 2025/06/07 13:09:26 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RPN.hpp"

RPN::RPN(std::string input)
{
	parseInput(input);
	// printTokens();
	doRPN();
}

RPN::~RPN()
{
}


RPN::RPN(RPN const &copy)
{
	std::cout << "RPN copy constructor called" << std::endl;
	*this = copy;
}

RPN &RPN::operator=(RPN const &rhs)
{
	std::cout <<  "Copy assigment operator for RPN Class called" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);	
}

void RPN::parseInput(std::string input)
{
	size_t	size = 0;
	char *str;

	if (isEmpty(input))
		throw std::runtime_error("Error: empty input.");

	str = const_cast<char *>(input.c_str());
	str = strtok(str, " ");
	if (!str)
		throw std::runtime_error("Error: empty input.");
	while (str != NULL)
	{
	if (isOperator(str))
	{
		if (size < 2)
			throw std::runtime_error("Parsing error: insufficient numbers for operation.");
		_tokens.push_back(str);
	}
	else
	{
		isValidNumber(str);
		++size;
		_tokens.push_back(str);
	}
	str = strtok (NULL, " ");
	}
	if (size >= 10)
		throw std::runtime_error("Parsing error: too many numbers to operate.");
}

// RPN simplifica la evaluación de expresiones mediante una pila. Cuando se encuentra un número,
// se empuja a la pila; cuando se encuentra un operador, se toman los dos últimos elementos de la 
//pila, se aplica el operador y el resultado se empuja nuevamente a la pila
void RPN::doRPN()
{
	long result = 0;
	long nb1;
	long nb2;

	for (std::list<std::string>::iterator it = _tokens.begin(); it != _tokens.end(); it++)
	{
		if (isOperator(*it))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Operation error: non valid operation.");
			nb1 = _stack.top();
			_stack.pop();
			nb2 = _stack.top();
			_stack.pop();
			result = operate(nb1, nb2, *it);
			_stack.push(result);
		}
		else
		{
			_stack.push(std::atol(it->c_str()));
		}
	}
	if (_stack.size() > 1)
		throw std::runtime_error("Operation error: non valid operation.");
	std::cout << "Result: " << this->_stack.top() << std::endl;
	
}

long RPN::operate(long nb1, long nb2, std::string op)
{
	char *c = const_cast<char *>(op.c_str());
	long result;

	switch (*c)
	{
		case '+':
			result = ((nb1 + nb2));
			break;
		
		case '-':
			result = ((nb2 - nb1));
			break;
		
		case '*':
			result = ((nb1 * nb2));
			break;
		
		case '/':
			result = ((nb2 / nb1));
			break;
	}
	return result;
}





bool RPN::isEmpty(std::string value)
{
	size_t i = 0;
	size_t spaces = 0;

	if (value.empty())
		return true;
	while (i != value.size())
	{
		if (isspace(value.at(i)))
			++spaces;
		++i;
	}
	if (spaces == value.size())
		return true;
	return false;
}

void RPN::isValidNumber(std::string value)
{
	long result = atol(value.c_str());

	if (result > INT_MAX || result < INT_MIN)
		throw std::runtime_error("Invalid number. Use INT number to operate.");
	if (result == 0 && value.size() > 1)
		throw std::runtime_error("Invalid input. Use INT number to operate.");
	
	char *str = const_cast<char *>(value.c_str());
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i == 0 && value[0] == '-')
			continue;
		else if (!isdigit(str[i]))
			throw std::runtime_error("Invalid input. Use INT number to operate.");
	}
}

void RPN::isValidOperation(std::string value)
{
	std::string operators[] = {"+", "-", "*", "/"};

	for (size_t i = 0; i < 4; i++) 
	{
		if (operators[i] == value)
			return ;
	}
	throw std::runtime_error("Invalid operator sign. Allow operations: + - * /.");
}

bool RPN::isOperator(std::string value) {
  std::string operators[] = {"+", "-", "*", "/"};

  for (size_t i = 0; i < 4; i++) 
  {
    if (operators[i] == value)
		return true;
  }
  return false;
}

void RPN::printTokens()
{
	std::cout << "<<<    List content    >>>>" << std::endl;
	for (std::list<std::string>::iterator it = _tokens.begin(); it != _tokens.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "<<<    List content end    >>>>" << std::endl;
	
}
