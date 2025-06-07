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

BitcoinExchange::BitcoinExchange()
{
	std::fstream    dataFile;
	std::map<std::string, float> dataBase;
	std::map<std::string, float>:: iterator itr;
	
	dataFile.open(DB);
	try
	{
		if (!dataFile.is_open())
			throw std::runtime_error("Error: could not open database file.");
		fileToDB(dataFile, dataBase, ",");
		_db = dataBase;
		std::cout << ">> The database has been successfully loaded." << std::endl;
		dataFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(std::string file_path)
{
	std::fstream    dataFile;
	std::map<std::string, float> dataBase;
	std::map<std::string, float>:: iterator itr;
	
	dataFile.open(file_path.c_str());
	try
	{
		if (!dataFile.is_open())
			throw std::runtime_error("Error: could not open database file.");
		fileToDB(dataFile, dataBase, ",");
		_db = dataBase;
		std::cout << ">> The database has been successfully loaded." << std::endl;
		dataFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::~BitcoinExchange()
{
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	std::cout <<  "Copy assigment operator for BitcoinExchange Class called" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);	
}



void	BitcoinExchange::fileToDB(std::fstream &file, std::map<std::string, float> &map, std::string delimiter)
{
	std::string line;
	std::string key;
	std::string value;
	bool		check_value = true;
	
	getline(file, line);
	
	if (line.find("exchange_rate", 0) != std::string::npos)
		check_value = false;
	if (line.find("date", 0) == std::string::npos)
		file.seekg(0);

	while (getline(file, line))
	{
		if (line.find(delimiter) != std::string::npos)
		{
			key = line.substr(0, line.find(delimiter));
			value = line.substr((line.find(delimiter) + 1), line.length());
			//Trim spaces
			key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			
			if (value.empty() || isEmpty(value))
				throw std::runtime_error("File error: Empty value.");
			if (!BitcoinExchange::isValidDate(key))
				throw std::runtime_error("Fatal error: Database creation error.");
			if (check_value)
				if (!BitcoinExchange::isValidValue(atof(value.c_str())))
					throw std::runtime_error("Fatal error: Database creation error.");
			map[key] = atof(value.c_str());
		}
		else	
		{
			throw std::runtime_error("File error: Missing separator.");
		}
	}
}

void	BitcoinExchange::fileToMap(std::fstream &file, std::multimap<std::string, float> &map, std::string delimiter)
{
	std::string line;
	std::string key;
	std::string value;
	
	getline(file, line);
	if (line.find("date", 0) == std::string::npos)
		file.seekg(0);

	while (getline(file, line))
	{
		if (line.find(delimiter) != std::string::npos)
		{
			key = line.substr(0, line.find(delimiter));
			value = line.substr((line.find(delimiter) + 1), line.length());
			//Trim spaces
			key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			
			if (value.empty() || isEmpty(value))
				throw std::runtime_error("File error: Empty value.");	
			map.insert(std::make_pair(key, atof(value.c_str())));
		}
		else	
		{
			throw std::runtime_error("File error: Missing separator.");
		}
	}
}

// A valid date will always be in the following format: Year-Month-Day 2009-01-02
bool	BitcoinExchange::isValidDate(std::string date)
{
	std::string tmp;
	size_t pos;

	pos = date.find('-');
	if (pos == std::string::npos)
	{
		std::cout << "Invalid date: '" << date << "' Missing separator." << std::endl;
		return (false);
	}
	tmp = date.substr(0, pos);
	if (tmp.size() != 4 || (atoi(tmp.c_str()) > 2025 && atoi(tmp.c_str()) < 1900))
	{
		std::cout << "Invalid date: '" << date << "' Wrong year format or value." << std::endl;
		return (false);
	}
	
	date.erase(0, pos + 1);
	
	pos = date.find('-');
	if (pos == std::string::npos)
	{
		std::cout << "Invalid date: '" << date << "' Missing separator." << std::endl;
		return (false);
	}

	tmp = date.substr(0, pos);
	if (tmp.size() != 2 || (atoi(tmp.c_str()) > 12 || atoi(tmp.c_str()) < 1))
	{
		std::cout << "Invalid date: '" << date << "' Wrong month format or value." << std::endl;
		return (false);
	}

	date.erase(0, pos + 1);

	tmp = date.substr(0, date.size());
	if (tmp.size() != 2 || (atoi(tmp.c_str()) > 31 || atoi(tmp.c_str()) < 1))
	{
		std::cout << "Invalid date: '" << date << "' Wrong day format or value." << std::endl;
		return (false);
	}
	return (true);
}

// A valid value must be either a float or a positive integer, between 0 and 1000
bool	BitcoinExchange::isValidValue(float value)
{
	if (value < 0 )
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (value > 1000)
	{
		std::cout << "Error: number too large." << std::endl;
		return (false);
	}
	return (true);
}

// 2011-01-03 => 3 = 0.9
void	BitcoinExchange::convertBitcoinOnDate(std::string inputDate, float amount)
{
	float	result;
	std::multimap<std::string, float>::iterator it;

	// std::cout << "Input Date " << inputDate << " amount: " << amount  << std::endl;
	//check valid input
	if (!isValidDate(inputDate) || !isValidValue(amount))
		return ;

	if (_db.find(inputDate) != _db.end())
	{
		it = _db.find(inputDate);
		result = it->second;
	}
	else
	{
		it = _db.lower_bound(inputDate);
		if (it != _db.end() && it->first == inputDate) 
		{
			result = it->second;
		}
		else 
		{
			if (it != _db.begin()) 
			{
				--it;
				result = it->second;
				// std::cout << "Nearest lower date: " << it->first << " -> " << it->second << std::endl;
			} else 
			{
				std::cout << "No exact ot earlier date available for conversion." << std::endl;
				return;
			}
		}
	}
	result *= amount;

	std::cout << it->first << " => " << amount << " = " << result << std::endl;
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

std::map<std::string, float> & BitcoinExchange::getDB()
{
	return (_db);
}

void BitcoinExchange::printDB()
{
	std::map<std::string, float>:: iterator itr;

	itr = _db.begin();
		while (itr != _db.end())
		{
			std::cout << "DB: " << itr->first << " Value: " << itr->second << std::endl;
			itr++;
		}
}