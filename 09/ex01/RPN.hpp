/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:09:32 by daviles-          #+#    #+#             */
/*   Updated: 2025/06/07 13:09:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _RPN
# define _RPN

# include <iostream>
# include <fstream>
# include <list>
# include <stack>
# include <exception>
# include <stdlib.h>
# include <algorithm>
# include <cstring>
# include <limits.h>


class RPN
{
	private:
 		std::stack<long> _stack;
		std::list<std::string> _tokens;

	public:
		// RPN();
		RPN(std::string input);
		RPN(RPN const &other);
		RPN & operator=(RPN const &rhs);
		~RPN();

		void parseInput(std::string input);
		void doRPN();
		long operate(long nb1, long nb2, std::string op);


		bool isEmpty(std::string value);
		void isValidNumber(std::string value);
		void isValidOperation(std::string value);
		bool isOperator(std::string value);

		void printTokens();
};


#endif