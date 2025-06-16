/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:51:56 by daviles-          #+#    #+#             */
/*   Updated: 2025/06/07 18:51:57 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(std::string input)
{
	parseInput(input);
	// printContainer<std::deque<unsigned int> >(_deque);
	std::cout << "Before:" << std::endl;
	printContainer<std::vector<unsigned int> >(_vector);
	sortVector();
	std::cout << "After:" << std::endl;
	printContainer<std::vector<unsigned int> >(_vector);
	// sort();
}

PmergeMe::~PmergeMe()
{
}


PmergeMe::PmergeMe(PmergeMe const &copy)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	std::cout <<  "Copy assigment operator for PmergeMe Class called" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);	
}

void PmergeMe::parseInput(std::string input)
{
	// size_t	size = 0;
	char *str;

	str = const_cast<char *>(input.c_str());
	str = strtok(str, " ");
	if (!str)
		throw std::runtime_error("Error: empty input.");
	while (str != NULL)
	{
		isValidNumber(str);
		// ++size;
		_deque.push_back(atoi(str));
		_vector.insert(_vector.end(), atoi(str));
		str = strtok (NULL, " ");
	}
	// if (size >= 10)
	// 	throw std::runtime_error("Parsing error: too many numbers to operate.");
}


void PmergeMe::isValidNumber(std::string value)
{
	long result = atol(value.c_str());

	if (result > INT_MAX || result < 0)
		throw std::runtime_error("Invalid number. Use positive INT number to operate.");
	if (result == 0 && value.size() > 1)
		throw std::runtime_error("Invalid input. Use positive INT number to operate.");
	
	char *str = const_cast<char *>(value.c_str());
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i == 0 && value[0] == '-')
			continue;
		else if (!isdigit(str[i]))
			throw std::runtime_error("Invalid input. Use positive INT number to operate.");
	}
}

void PmergeMe::sortVector()
{
	bool is_odd = _vector.size() % 2;
	std::vector<unsigned int>::iterator it2;

	for (std::vector<unsigned int>::iterator it1 = _vector.begin(); it1 != _vector.end(); std::advance(it1,2))
	{
		it2 = it1 + 1;
		if (is_odd && it2 + 1 == _vector.end())
			break;
		sortSwapTwo<std::vector<unsigned int> >(it1, it2);
	}
}