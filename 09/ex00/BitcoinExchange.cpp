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
		if (line.find(delimiter) != std::string::npos)
		{
			key = line.substr(0, line.find(delimiter));
			value = line.substr((line.find(delimiter) + 1), line.length());
			if (value.empty() || isEmpty(value))
				throw std::runtime_error("File error: Empty value.");
			// std::cout << "key: " << key << std::endl;
			std::cout << "value: " << value << std::endl;

			BitcoinExchange::isValidDate(key);
			BitcoinExchange::isValidValue(value);
			map[key] = atoi(value.c_str());
		}
		else	
		{
			throw std::runtime_error("File error: Missing separator.");
		}
		// std::cout << "Key: " << key << " Value: " << value << std::endl;
	}
}
// A valid date will always be in the following format: Year-Month-Day 2009-01-02
void	BitcoinExchange::isValidDate(std::string date)
{
	std::string tmp;
	size_t pos;

	pos = date.find('-');
	if (pos == std::string::npos)
		throw std::runtime_error("Invalid date: Missing separator.");
	tmp = date.substr(0, pos);
	// std::cout << "YEAR " << tmp << std::endl;
	if (tmp.size() != 4 || (atoi(tmp.c_str()) > 2025 && atoi(tmp.c_str()) < 1900))
		throw std::runtime_error("Invalid date: Wrong year format or value.");
	
	date.erase(0, pos + 1);
	
	pos = date.find('-');
	if (pos == std::string::npos)
		throw std::runtime_error("Invalid date: Missing separator.");

	tmp = date.substr(0, pos);
	// std::cout << "MONTH " << tmp << std::endl;
	if (tmp.size() != 2 || (atoi(tmp.c_str()) > 12 || atoi(tmp.c_str()) < 1))
		throw std::runtime_error("Invalid date: Wrong month format or value.");		

	date.erase(0, pos + 1);

	tmp = date.substr(0, date.size());
	if (tmp.size() != 2 || (atoi(tmp.c_str()) > 31 || atoi(tmp.c_str()) < 1))
		throw std::runtime_error("Invalid date: Wrong day format or value.");		
	// std::cout << "day " << tmp << std::endl;

}

// A valid value must be either a float or a positive integer, between 0 and 1000
void	BitcoinExchange::isValidValue(std::string value)
{
	float 	v = atof(value.c_str());

	std::cout << "int " << v << std::endl;
	if (v < 0 || v > 1000)
		throw std::runtime_error("Invalid value: value exceed the limits.");		

}

bool BitcoinExchange::isEmpty(std::string value)
{
	size_t i = 0;
	size_t spaces = 0;

	if (value.empty())
		return true;
	while (i != value.size())
	{
		if (isspace(value.at(i)))
			++spaces;
		++i;
	}
	if (spaces == value.size())
		return true;
	return false;
}