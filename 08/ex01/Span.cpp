/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:09:24 by daviles-          #+#    #+#             */
/*   Updated: 2025/05/22 13:09:26 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int n): _size(n)
{
}

Span::~Span()
{
	_span.clear();
}

Span::Span(Span const &copy)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = copy;
}

Span &Span::operator=(Span const &rhs)
{
	std::cout <<  "Copy assigment operator for Span Class called" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);	
}

void Span::addNumber(int nb)
{
	if (_span.size() + 1 > _size)
		throw std::runtime_error("Impossible to add number. Span size is full.");
	_span.push_back(nb);
}



	
int Span::shortestSpan()
{
	if (_span.size() <= 1)
		throw std::runtime_error("Not enough elements, no span can be found.");
	
	int	min = 0;
	int	gap;

	for (std::list<int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		for (std::list<int>::iterator j = it; j != _span.end(); j++)
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
	
	
int Span::longestSpan()
{
	if (_span.size() <= 1)
		throw std::runtime_error("Not enough elements, no span can be found.");
	
	int	max = 0;
	int	gap;

	for (std::list<int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		for (std::list<int>::iterator j = it; j != _span.end(); j++)
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
	
void Span::printSpan()
{
	for (std::list<int>::iterator it = _span.begin(); it != _span.end(); it++)
		std::cout << *it << std::endl;
}