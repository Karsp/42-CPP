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
	// size_t	start = 0;
	// size_t	end;
	char *str;

	if (isEmpty(input))
		throw std::runtime_error("Error: empty input.");

	str = const_cast<char *>(input.c_str());
	str = strtok(str, " ");
	if (!str)
	{
		std::cout << 0 << std::endl;
		return ;
	}
  while (str != NULL)
  {
    std::cout << str << std::endl;
    str = strtok (NULL, " ");
  }

	// while (input[start])
	// {
	// 	if (input[start] == ' ')
	// 		while(input[start] == ' ')
	// 			++start;
		
	// 	end = input.find(' ', start);
	// 	if (end == std::string::npos)
	// 		end = input.size();
	// 	_tokens.push_back(input.substr(start, end));
	// 	std::cout << input.substr(start, end) << std::endl;
	// 	input.erase(start, end);
	// 	start = 0;
	// }
	
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