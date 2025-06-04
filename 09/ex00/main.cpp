/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:04 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/18 15:41:06 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "BitcoinExchange.h"


// void	fileToMap(std::fstream &file, std::map<std::string, float> &map, std::string delimiter)
// {
// 	std::string line;
// 	std::string key;
// 	std::string value;
// 	// bool		allowEmptyValue = true;
	
// 	// getline(file, line);
	
// 	// std::cout << "Line 1: " << line << std::endl;
// 	// if (line.find("exchange_rate", 0) != std::string::npos)
// 	// 	allowEmptyValue = false;


	
// 	while (getline(file, line))
// 	{
// 		std::cout << "Line: " << line << std::endl;
// 		// if (line.find("date"))
// 		// {
// 		// 	getline(file, line);
// 		// }	
// 		if (line.find(delimiter) != std::string::npos)
// 		{
// 			key = line.substr(0, line.find(delimiter));
// 			value = line.substr((line.find(delimiter) + 1), line.length());
// 			BitcoinExchange::isValidDate(key);
// 			BitcoinExchange::isValidValue(value);
// 			map[key] = atoi(value.c_str());
// 		}
// 		else	
// 		{
// 			throw std::runtime_error("File error: Empty value is not allowed.");
// 		}
// 		std::cout << "Key: " << key << " Value: " << value << std::endl;
// 	}
// }

int main(int argc, char **argv)
{
    std::fstream    inFile;
	std::map<std::string, float>:: iterator itr;
	std::map<std::string, float> inputData;

    if (argc != 2)
        return (std::cout << "Bad input. Please enter a filename." << std::endl, 0);

    inFile.open(argv[1]);
	if (!inFile.is_open())
        return (std::cout << "Error: could not open file." << std::endl, 0);


	BitcoinExchange btc = BitcoinExchange();
	// BitcoinExchange btc = BitcoinExchange("data.csv");
	if (btc.getDB().empty())
	{
		std::cout << "DB creation failed. Exiting program." << std::endl;
		return (1);
	}
	itr = btc.getDB().begin();
		while (itr != btc.getDB().end())
		{
			std::cout << "DB: " << itr->first << " Value: " << itr->second << std::endl;
			itr++;
		}
	try
	{
		// std::cout << "HERE" << std::endl;
		btc.fileToMap(inFile, inputData, "|");
		// std::cout << "HERE 2" << std::endl;
		itr = inputData.begin();
		while (itr != inputData.end())
		{
			std::cout << "MAP: " << itr->first << " Value: " << itr->second << std::endl;
			itr++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Input file parsing failed. Exiting program." << std::endl;

	}
	

	for (std::map<std::string, float>:: iterator itr = btc.getDB().begin(); itr != btc.getDB().end(); itr++)
	{
		std::cout << "database: " << itr->first << " Value: " << itr->second << std::endl;

	}
	

	inFile.close();
	return(0);
}

