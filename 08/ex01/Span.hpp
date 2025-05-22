#pragma once
#ifndef _Span_HPP
# define _Span_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <exception>
# include <iterator> //std::distance

class Span
{
	private:
		unsigned int _size;
		std::list<int> _span;

	public:
		Span(unsigned int n);
		~Span();
		Span(Span const &other);
		Span & operator=(Span const &rhs);

		void addNumber(int nb);
		
		template <typename It>
		void addNumber(It begin, It end)
		{
			int dist = std::distance(begin, end);
			
			if (_span.size() + dist > _size)
				throw std::runtime_error("Impossible to add number. Span size is full.");
			while (begin != end)
			{
				_span.push_back(*begin);
				++begin;
			}
		}

		int shortestSpan();
		int longestSpan();
		
		void printSpan();
		const std::list<int>& getSpan() const { return _span; }

};


#endif
