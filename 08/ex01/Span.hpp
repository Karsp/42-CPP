#pragma once
#ifndef _Span_HPP
# define _Span_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <exception>

class Span
{
	private:
		unsigned int _size;
		std::list<int> _span;

	public:
		Span(unsigned int n);
		~Span();

		void addNumber(int nb);
		int shortestSpan();
		int longestSpan();

};


#endif
