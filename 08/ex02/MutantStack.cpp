/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:09:24 by daviles-          #+#    #+#             */
/*   Updated: 2025/05/22 13:09:26 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


MutantStack::MutantStack(unsigned int n): _size(n)
{
}

MutantStack::~MutantStack()
{
	_MutantStack.clear();
}

void MutantStack::addNumber(int nb)
{
	if (_MutantStack.size() + 1 > _size)
		throw std::runtime_error("Impossible to add number. MutantStack size is full.");
	_MutantStack.push_back(nb);
}



	
int MutantStack::shortestMutantStack()
{
	if (_MutantStack.size() <= 1)
		throw std::runtime_error("Not enough elements, no MutantStack can be found.");
	
	int	min = 0;
	int	gap;

	for (std::list<int>::iterator it = _MutantStack.begin(); it != _MutantStack.end(); it++)
	{
		for (std::list<int>::iterator j = it; j != _MutantStack.end(); j++)
		{
			gap = (*it - *j);
			// std::cout << "gap " << gap << " Min " << min << std::endl;
			if (gap < 0)
				gap *= -1;
			if (min == 0 || (gap != 0 && gap < min))
				min = gap;
		}
	}
	return (min);
}
	
	
int MutantStack::longestMutantStack()
{
	if (_MutantStack.size() <= 1)
		throw std::runtime_error("Not enough elements, no MutantStack can be found.");
	
	int	max = 0;
	int	gap;

	for (std::list<int>::iterator it = _MutantStack.begin(); it != _MutantStack.end(); it++)
	{
		for (std::list<int>::iterator j = it; j != _MutantStack.end(); j++)
		{
			gap = (*it - *j);
			// std::cout << "gap " << gap << " max " << max << std::endl;
			if (gap < 0)
				gap *= -1;
			if (max == 0 || (gap != 0 && gap > max))
				max = gap;
		}
	}
	return (max);
}
	
void MutantStack::printMutantStack()
{
	for (std::list<int>::iterator it = _MutantStack.begin(); it != _MutantStack.end(); it++)
		std::cout << *it << std::endl;
}