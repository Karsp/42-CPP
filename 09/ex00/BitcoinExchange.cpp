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
	// std::cout << _db["2009-01-11"] << std::endl;
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
			std::cout << "key: " << key << std::endl;
			std::cout << "value: " << value << std::endl;

			if (!BitcoinExchange::isValidDate(key))
				throw std::runtime_error("Fatal error: Database creation error.");
			if (check_value)
				if (!BitcoinExchange::isValidValue(value))
					throw std::runtime_error("Fatal error: Database creation error.");
			map[key] = atof(value.c_str());
		}
		else	
		{
			throw std::runtime_error("File error: Missing separator.");
		}
		// std::cout << "Key: " << key << " Value: " << value << std::endl;
	}
}

void	BitcoinExchange::fileToMap(std::fstream &file, std::map<std::string, float> &map, std::string delimiter)
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
				// std::cout << "Parsing error: Empty value on key: " << key << std::endl;
			// std::cout << "key: " << key << std::endl;
			// std::cout << "value: " << value << std::endl;

			// BitcoinExchange::isValidDate(key);
			// if (check_value)
			// 	BitcoinExchange::isValidValue(value);
			map[key] = atof(value.c_str());
		}
		else	
		{
			throw std::runtime_error("File error: Missing separator.");
		}
		// std::cout << "Key: " << key << " Value: " << value << std::endl;
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
bool	BitcoinExchange::isValidValue(std::string value)
{
	float 	v = atof(value.c_str());

	if (v < 0 )
	{
		std::cout << "Error: '" << value << "' is not a positive number." << std::endl;
		return (false);
	}
	else if (v > 1000)
	{
		std::cout << "Error: '" << value << "' is a number too large." << std::endl;
		return (false);
	}
	return (true);
}

// 2011-01-03 => 3 = 0.9
void	BitcoinExchange::convertBitcoinOnDate(std::string inputDate, float amount)
{
	float	result;
	std::map<std::string, float>::iterator it;

	//check valid input
	std::cout << "Input Date " << inputDate << std::endl;
	if (_db.find(inputDate) != _db.end())
	{
		result = _db.find(inputDate)->second;
		std::cout << "Found Date " << _db.find(inputDate)->first << std::endl;
	}
	else
	{
		it = _db.lower_bound(inputDate);
		if (it != _db.end() && it->first == inputDate) 
		{
        std::cout << "Exact date found: " << it->first << " -> " << it->second << std::endl;
		} else {
			if (it != _db.begin()) {
				--it; // move to the previous (lower) date
				std::cout << "Nearest lower date: " << it->first << " -> " << it->second << std::endl;
			} else {
				std::cout << "No earlier date available." << std::endl;
			}
		}
		result = it->second;
	// std::cout << "Date " << it->first << std::endl;
	}
	result *= amount;

	// std::cout << "Final Result " << result << std::endl;

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