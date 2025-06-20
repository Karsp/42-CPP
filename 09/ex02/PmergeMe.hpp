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
# include <iomanip> //setprecision

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
		// void sortVector(std::vector<unsigned int> &container);
		// void sortDeque();
		
		void sortPairs();
		void isValidNumber(std::string value);
		
		template <typename T> void sortFordJohnson(T& container, int pair_level);

    	template <typename T> void sortSwap(T it, int pair_level);

};


// static long getJacobsthalNumber(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

long _jacobsthal_number(long n);


template <typename T> T itNext(T it, int steps)
{
    std::advance(it, steps);
    return it;
}


template <typename T> void PmergeMe::sortSwap(T it, int pair_level)
{
    T start = itNext(it, -pair_level + 1);
    T end = itNext(start, pair_level);
    while (start != end)
    {
        std::iter_swap(start, itNext(start, pair_level));
        start++;
    }
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

template <typename T> bool compVals(T lv, T rv) {
	return *lv < *rv;
}

template <typename T> void PmergeMe::sortFordJohnson(T& container, int pair_level)
{
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;
	/* If there is an odd pair, we ignore it during swapping.
       It will go to the pend as the last pair. */
    bool is_odd = pair_units_nbr % 2 == 1;

	 /* It's important to caluclate the end position until which we should iterate.
       We can have a set of values like:
       ((1 2) (3 4)) ((3 8) (2 6)) | 0
       where there are numbers (0 in this case) which can't even form a pair.
       Those values should be ignored. */
    Iterator start = container.begin();
    Iterator last = itNext(container.begin(), pair_level * (pair_units_nbr));
    Iterator end = itNext(last, -(is_odd * pair_level));

	/* Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
       number. After each swap we recurse. */
    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
        Iterator this_pair = itNext(it, pair_level - 1);
        Iterator next_pair = itNext(it, pair_level * 2 - 1);
        if (compVals(next_pair, this_pair))
        {
            sortSwap(this_pair, pair_level);
        }
    }
    sortFordJohnson(container, pair_level * 2);

    /* Main contains an already sorted sequence.
       Pend stores a yet to be sorted numbers.
       List data structure for quick random insertion and deletion.
       They contain iterators instead of the numbers themselves because
       iterators + pair_level contain all the information about the stored
       ranges of numbers. */
    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    /* Initialize the main chain with the {b1, a1}. */
    main.insert(main.end(), itNext(container.begin(), pair_level - 1));
    main.insert(main.end(), itNext(container.begin(), pair_level * 2 - 1));

    /* Insert the rest of a's into the main chain.
       Insert the rest of b's into the pend. */
    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
        pend.insert(pend.end(), itNext(container.begin(), pair_level * (i - 1) - 1));
        main.insert(main.end(), itNext(container.begin(), pair_level * i - 1));
    }

    /* Insert an odd element to the pend, if there are any. */
    if (is_odd)
    {
        pend.insert(pend.end(), itNext(end, pair_level - 1));
    }

    /* Insert the pend into the main in the order determined by the
       Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
       During insertion, main numbers serve as an upper bound for inserting numbers,
       in order to save number of comparisons, as we know already that, for example,
       b5 is lesser than a5, we binary search only until a5, not until the end
       of the container.
           We can calculate the index of the bound element. With the way I do it,
           the index of the bound is inserted_numbers + current_jacobsthal_number. */
    int prev_jacobsthal = _jacobsthal_number(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++)
    {
        int curr_jacobsthal = _jacobsthal_number(k);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
        if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<Iterator>::iterator pend_it = itNext(pend.begin(), jacobsthal_diff - 1);
        typename std::vector<Iterator>::iterator bound_it =
            itNext(main.begin(), curr_jacobsthal + inserted_numbers);
        while (nbr_of_times)
        {
            typename std::vector<Iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, compVals<Iterator>);
            typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            /* Sometimes the inserted number in inserted at the exact index of where the bound should be.
			   When this happens, it eclipses the bound of the next pend, and it does more comparisons
			   than it should. We need to offset when this happens. */
            offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = itNext(main.begin(), curr_jacobsthal + inserted_numbers - offset);
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
		offset = 0;
    }

    /* Insert the remaining elements in the reversed order. Here we also want to
       perform as less comparisons as possible, so we calculate the starting bound
       to insert pend number to be the pair of the first pend number. If the first
       pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
       With the way I do it the index of bound is
       size_of_main - size_of_pend + index_of_current_pend. */
    for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        typename std::vector<Iterator>::iterator curr_pend = itNext(pend.begin(), i);
        typename std::vector<Iterator>::iterator curr_bound =
            itNext(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, compVals<Iterator>);
        main.insert(idx, *curr_pend);
    }

    /* Use copy vector to store all the numbers, in order not to overwrite the
       original iterators. */
    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_level; i++)
        {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    /* Replace values in the original container. */
    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}


#endif