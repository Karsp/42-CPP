/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:20 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/18 15:41:22 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#ifndef _BITCOINEX
# define _BITCOINEX

# include <iostream>
# include <fstream>
# include <map>
# include <exception>

# define DB "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, int> _db;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange & operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		void	fileToMap(std::fstream &file, std::map<std::string, int> &map, std::string delimiter);
		static void	isValidDate(std::string date);
		static void	isValidValue(std::string value);
		int			closer_date();
		
};


#endif

