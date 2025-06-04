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

	// std::cout << "DATE " << date << "|" << std::endl;
	pos = date.find('-');
	if (pos == std::string::npos)
	{
		std::cout << "Invalid date: '" << date << "' Missing separator." << std::endl;
		return (false);
	}
		// throw std::runtime_error("Invalid date: Missing separator.");
	tmp = date.substr(0, pos);
	// std::cout << "YEAR " << tmp << std::endl;
	if (tmp.size() != 4 || (atoi(tmp.c_str()) > 2025 && atoi(tmp.c_str()) < 1900))
	{
		std::cout << "Invalid date: '" << date << "' Wrong year format or value." << std::endl;
		return (false);
	}
		// throw std::runtime_error("Invalid date: ");
	
	date.erase(0, pos + 1);
	
	pos = date.find('-');
	if (pos == std::string::npos)
	{
		std::cout << "Invalid date: '" << date << "' Missing separator." << std::endl;
		return (false);
	}

	tmp = date.substr(0, pos);
	// std::cout << "MONTH " << tmp << std::endl;
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
		// throw std::runtime_error("Invalid date: Wrong day format or value.");		
	// std::cout << "DAY " << tmp << std::endl;
	return (true);
}

// A valid value must be either a float or a positive integer, between 0 and 1000
bool	BitcoinExchange::isValidValue(std::string value)
{
	float 	v = atof(value.c_str());

	// if (v < 0 || v > 1000)
	// 	throw std::runtime_error("Invalid value: value exceed the limits.");		
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

// void	BitcoinExchange::convertBitcoinOnDate(std::map<std::string, float> &input)
// {

// }

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