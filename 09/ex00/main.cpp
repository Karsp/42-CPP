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


// void	fileToMap(std::fstream &file, std::map<std::string, int> &map, std::string delimiter)
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
    std::fstream    dataFile;
	std::map<std::string, int>:: iterator itr;
	std::map<std::string, int> fileData;

    if (argc != 2)
        return (std::cout << "Bad input. Please enter a filename." << std::endl, 0);

    inFile.open(argv[1]);
	if (!inFile.is_open())
        return (std::cout << "Error: could not open file." << std::endl, 0);


	BitcoinExchange btc = BitcoinExchange();
	// BitcoinExchange btc = BitcoinExchange("data.csv");

    // dataFile.open("testdata.csv");
	// if (!dataFile.is_open())
    //     return (std::cout << "Error: could not open database file." << std::endl, 0);

	// try
	// {
	// 	fileToMap(dataFile, dataBase, ",");
	// 	fileToMap(inFile, fileData, "|");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// itr = fileData.begin();
	// while (itr != fileData.end())
	// {
	// 	std::cout << "MAP: " << itr->first << " Value: " << itr->second << std::endl;
	// 	itr++;
	// }
	// itr = dataBase.begin();
	// while (itr != dataBase.end())
	// {
	// 	std::cout << "database: " << itr->first << " Value: " << itr->second << std::endl;
	// 	itr++;
	// }

	// inFile.close();
	// dataFile.close();
	return(0);
}

