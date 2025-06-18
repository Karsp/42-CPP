/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:52:08 by daviles-          #+#    #+#             */
/*   Updated: 2025/06/07 18:52:10 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef _PmergeMe_HPP
# define _PmergeMe_HPP

# include <iostream>
# include <algorithm>
# include <bits/types/clock_t.h>
# include <string>
# include <vector>
# include <cstring>
# include <deque>
# include <limits.h>

class PmergeMe
{
	private:
		std::vector<unsigned int> _vector;
		std::deque<unsigned int> _deque;
		clock_t start_vec;
		clock_t start_deq;
		long _jacobsthal_number(long n);

	public:
		PmergeMe(std::string input);
		PmergeMe(PmergeMe const &other);
		PmergeMe & operator=(PmergeMe const &rhs);
		~PmergeMe();

		void parseInput(std::string input);
		void sortVector(std::vector<unsigned int> container);
		void sortDeque();
		void sortPairs();
		

		void isValidNumber(std::string value);


};


template <typename T>
static void sortSwap(typename T::iterator &it1,typename T::iterator &it2)
{
	if (*it1 > *it2)
	{
		int	tmp = *it2;
		*it2 = *it1;
		*it1 = tmp;
	}
	return ;
};

template <typename T>
static void sortSwapTwo(size_t id1,size_t id2, T &container)
{
	typename T::iterator it1 = container.begin() + id1;
	typename T::iterator it2 = container.begin() + id2;

	if (*it1 > *it2)
	{
		int	tmp = *it2;
		*it2 = *it1;
		*it1 = tmp;
	}
	// std::cout << *it1 << " - " << *it2 << std::endl;
	return ;
};

template <typename T>
static void printContainer(T container)
{
	size_t i = 0;
	// typename T::const_iterator end = container.end();

	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		// if (i >= 10)
		// {
		// 	std::cout << "[...]" ;
		// 	break;
		// }
		std::cout << *it << " " ;
		++i;
	}
	std::cout << "" << std::endl;
};

template <typename T>
static bool isSorted(T& container) {
  typename T::iterator it = container.begin();
  for (; it != container.end() - 1; it++) {
    if (*it > *(it + 1)) return false;
  }
  return true;
}


#endif