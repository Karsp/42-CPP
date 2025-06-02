/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:32 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/18 15:41:36 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange(/* args */)
{
	std::fstream    dataFile;
	std::map<std::string, int> dataBase;
	std::map<std::string, int>:: iterator itr;
	
	dataFile.open(DB);
	try
	{
		if (!dataFile.is_open())
			throw std::runtime_error("Error: could not open database file.");
		fileToMap(dataFile, dataBase, ",");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}



BitcoinExchange::~BitcoinExchange()

{

}


void	BitcoinExchange::fileToMap(std::fstream &file, std::map<std::string, int> &map, std::string delimiter)
{
	std::string line;
	std::string key;
	std::string value;
	// bool		allowEmptyValue = true;
	
	getline(file, line);
	std::cout << "Line 1: " << line << std::endl;
	if (line.find("exchange_rate", 0) == std::string::npos)
		file.seekg(0);

	while (getline(file, line))
	{
		std::cout << "Line: " << line << std::endl;
		// if (line.find("date"))
		// {
		// 	getline(file, line);
		// }	
		if (line.find(delimiter) != std::string::npos)
		{
			key = line.substr(0, line.find(delimiter));
			value = line.substr((line.find(delimiter) + 1), line.length());
			BitcoinExchange::isValidDate(key);
			BitcoinExchange::isValidValue(value);
			map[key] = atoi(value.c_str());
		}
		else	
		{
			throw std::runtime_error("File error: Missing separator or empty value.");
		}
		std::cout << "Key: " << key << " Value: " << value << std::endl;
	}
}

void	BitcoinExchange::isValidDate(std::string date)
{

}

void	BitcoinExchange::isValidValue(std::string value)
{

}