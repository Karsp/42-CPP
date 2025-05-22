#pragma once
#ifndef _MutantStack_HPP
# define _MutantStack_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <exception>
# include <iterator> //std::distance

class MutantStack
{
	private:
		unsigned int _size;
		std::list<int> _MutantStack;

	public:
		MutantStack(unsigned int n);
		~MutantStack();

		void addNumber(int nb);
		
		template <typename It>
		void addNumber(It begin, It end)
		{
			int dist = std::distance(begin, end);
			
			if (_MutantStack.size() + dist > _size)
				throw std::runtime_error("Impossible to add number. MutantStack size is full.");
			while (begin != end)
			{
				_MutantStack.push_back(*begin);
				++begin;
			}
		}

		int shortestMutantStack();
		int longestMutantStack();
		
		void printMutantStack();
		const std::list<int>& getMutantStack() const { return _MutantStack; }

};


#endif
