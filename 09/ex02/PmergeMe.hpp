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
# include <cmath>

class PmergeMe
{
	private:
		std::vector<unsigned int> _vector;
		std::deque<unsigned int> _deque;
		clock_t start_vec;
		clock_t start_deq;
		// long _jacobsthal_number(long n);
		int _count;

	public:
		PmergeMe(std::string input);
		PmergeMe(PmergeMe const &other);
		PmergeMe & operator=(PmergeMe const &rhs);
		~PmergeMe();

		void parseInputFillContainers(std::string input);
		void sortVector(std::vector<unsigned int> &container);
		void sortDeque();
		void sortPairs();
		

		void isValidNumber(std::string value);

		/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
		// static long getJacobsthalNumber(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

};


static long getJacobsthalNumber(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }


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

template <typename T> T itNext(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

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


template <typename T>
void sortFordJohnson(T &container)
{
	typedef typename T::iterator Iterator;

	bool is_odd = container.size() % 2;
	size_t id2;
	T a; //mayores
	T b; //menores

	if (container.size() / 2 < 2)
	{
		// Sort the shortest container
		for (size_t i = 0; i < container.size(); i++)
		{
			if (isSorted<T>(container))
				break;
			sortSwapTwo<T>(i, i + 1, container);
		}
		return; 
	}
	
	for (size_t id1 = 0; id1 < container.size(); id1 += 2)
	{
		id2 = id1 + 1;
		if (is_odd && id2 + 1 >= container.size())
		{
			// std::cout << "ODD: " << container[id1] << std::endl;
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
	sortFordJohnson(b);
	sortFordJohnson(a);

	// Merge insertion with Jaconbsthal number of elements
	if (!b.empty())
	{
		a.insert(a.begin(), b[0]);
		b.erase(b.begin());
	}

	int prev_jacobsthal = getJacobsthalNumber(1);
    int inserted_numbers = 0;

	for (size_t k = 2;; ++k)
	{
		int curr_jacobsthal = getJacobsthalNumber(k);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;

        if (jacobsthal_diff > static_cast<int>(b.size()))
            break;

		int nbr_of_times = jacobsthal_diff;
		
		Iterator pend_it = itNext(b.begin(), jacobsthal_diff - 1);
        Iterator bound_it =
		itNext(a.begin(), curr_jacobsthal + inserted_numbers );
        while (nbr_of_times)
        {
            Iterator idx =
                std::upper_bound(a.begin(), bound_it, *pend_it);
            Iterator inserted = a.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = b.erase(pend_it);
            std::advance(pend_it, -1);
            /* Sometimes the inserted number in inserted at the exact index of where the bound should be.
			   When this happens, it eclipses the bound of the next pend, and it does more comparisons
			   than it should. We need to offset when this happens. */
            offset += (inserted - a.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = itNext(a.begin(), curr_jacobsthal + inserted_numbers - offset);
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
		offset = 0;
	}

	std::cout << "Before last insertion" << std::endl;
	printContainer< std::vector<unsigned int> >(a);
	printContainer< std::vector<unsigned int> >(b);
	/* Insert the remaining elements in the reversed order. Here we also want to
       perform as less comparisons as possible, so we calculate the starting bound
       to insert pend number to be the pair of the first pend number. If the first
       pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
       With the way I do it the index of bound is
       size_of_main - size_of_pend + index_of_current_pend. */
    for (ssize_t i = b.size() - 1; i >= 0; i--)
    {
        Iterator curr_pend = itNext(b.begin(), i);
        Iterator curr_bound =
            itNext(a.begin(), a.size() - b.size() + i + is_odd);
        Iterator idx =
            std::upper_bound(a.begin(), curr_bound, *curr_pend);
        a.insert(idx, *curr_pend);
    }

	container = a;
}



#endif