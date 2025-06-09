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

	public:
		PmergeMe(std::string input);
		PmergeMe(PmergeMe const &other);
		PmergeMe & operator=(PmergeMe const &rhs);
		~PmergeMe();

		void parseInput(std::string input);
		void sortVector();
		void sortDeque();
		

		void isValidNumber(std::string value);


};


template <typename T>
void sortTwo(typename T::iterator &it1,typename T::iterator &it2)
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
void printContainer(T &list)
{
	for (typename T::iterator<unsigned int> &it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << " " << std::endl;
	}
	
};


#endif