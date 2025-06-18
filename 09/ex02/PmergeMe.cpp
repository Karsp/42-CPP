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
	sortVector(_vector);
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
	// Check repeated?

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

void PmergeMe::sortVector(std::vector<unsigned int> container)
{
	bool is_odd = container.size() % 2;
	size_t id2;
	std::vector<unsigned int> a; //mayores
	std::vector<unsigned int> b; //menores

	if (container.size() / 2 < 2)
	{
		// Sort the shortest container
		for (size_t i = 0; i < container.size(); i++)
		{
			if (isSorted<std::vector<unsigned int> >(container))
				break;
			sortSwapTwo<std::vector<unsigned int> >(i, i + 1, container);
		}
		return; 
	}
	
	for (size_t id1 = 0; id1 < container.size(); id1 += 2)
	{
		id2 = id1 + 1;
		if (is_odd && id2 + 1 >= container.size())
		{
			b.push_back(container[id1]);
			break;
		}
		if (container[id1] > container[id2])
		{
			a.push_back(container[id1]);
			b.push_back(container[id2]);
		}
		else
		{
			a.push_back(container[id2]);
			b.push_back(container[id1]);
		}
	}
	sortVector(a);
	sortVector(b);
	std::cout << "Recursive" << std::endl;
	printContainer(a);
	printContainer(b);

	// Merge insertion
	// if (a.size() == 0 || b.size() == 0)
	if (b.size() == 0)
		return;
	
	int prev_jacobsthal = _jacobsthal_number(1);
    int inserted_numbers = 0;
	for (size_t id1 = 0; id1 < b.size(); ++id1)
	{
		if (id1 == 0)
		{
			a.insert(a.begin(), b[0]);
		}
		else
		{

			a.push_back(b[id1]);
		}
		// sortSwapTwo<std::vector<unsigned int> >(id1, id2, _vector);
	}

	std::cout << "Insertion" << std::endl;
	printContainer(a);
}