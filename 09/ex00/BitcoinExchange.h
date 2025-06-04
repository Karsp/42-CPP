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
# include <stdlib.h>
# include <algorithm>

# define DB "testdata.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, int> _db;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string file_path);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange & operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		void	fileToDB(std::fstream &file, std::map<std::string, int> &map, std::string delimiter);
		void	fileToMap(std::fstream &file, std::map<std::string, int> &map, std::string delimiter);
		static bool	isValidDate(std::string date);
		static bool	isValidValue(std::string value);
		int			closer_date();
		
		void		convertBitcoinOnDate(std::map<std::string, int> &input);

		static bool	isEmpty(std::string value);

		std::map<std::string, int> & getDB();
		
};


#endif

