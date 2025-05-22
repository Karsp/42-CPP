#pragma once
#ifndef _MutantStack_HPP
# define _MutantStack_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <exception>
# include <iterator> //std::distance
# include <stack>
# include <deque>

# include <iterator> // For std::forward_iterator_tag
# include <cstddef>  // For std::ptrdiff_t

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef std::deque<T> container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;

		MutantStack() {}

		MutantStack(const MutantStack &copy)
			: std::stack<T>(copy) {}

		MutantStack &operator=(const MutantStack &rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		~MutantStack() {}

		iterator begin() { return this->c.begin(); }
		iterator end()   { return this->c.end(); }

		void print() const
		{
			typename container_type::const_iterator it = this->c.begin();
			typename container_type::const_iterator ite = this->c.end();

			std::cout << "--\n";
			while (it != ite)
			{
				std::cout << *it << "\n";
				++it;
			}
			std::cout << "--" << std::endl;
		}
};


#endif
