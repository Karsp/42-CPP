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
	// std::cout << "input" << input << std::endl;
	parseInputFillContainers(input);
	_count = 0;
	// printContainer<std::deque<unsigned int> >(_deque);
	
	// clock_t start_vec = clock();
	// sortVector(_vector);
	 sortFordJohnson<std::vector<unsigned int> >(_vector, 1);
    // clock_t end_vec = clock();
    // double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

	// sortFordJohnson<std::vector<unsigned int> >(_vector);
	// std::cout << "After:" << std::endl;
	// printContainer<std::vector<unsigned int> >(_vector);
	
	
    // std::cout << "\033[31mBefore\033[00m: " << std::endl;
	// printContainer<std::vector<unsigned int> >(_vector);
    std::cout << "\033[32mAfter\033[00m:  " << std::endl;
	printContainer<std::vector<unsigned int> >(_vector);

    // std::cout << "Time to process a range of " << _vector.size()
    //           << " elements with std::vector: " << std::fixed << std::setprecision(6)
    //           << time_elapsed_vec << "s\n";
    // std::cout << "Time to process a range of " << _vector.size()
    //           << " elements with std::deque:  " << std::fixed << std::setprecision(6)
    //           << time_elapsed_deque << "s\n";
	// printContainer<std::vector<unsigned int> >(_vector);
	if (isSorted<std::vector<unsigned int> >(_vector))
		std::cout << "Sorted" << std::endl;
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
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return (*this);	
}

void PmergeMe::parseInputFillContainers(std::string input)
{
	char *str;

	str = const_cast<char *>(input.c_str());
	str = strtok(str, " ");
	if (!str)
		throw std::runtime_error("Error: empty input.");
	while (str != NULL)
	{
		isValidNumber(str);
		_deque.push_back(atoi(str));
		_vector.insert(_vector.end(), atoi(str));
		str = strtok (NULL, " ");
	}
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

/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
long _jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }
