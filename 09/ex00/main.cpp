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
#include <fstream>
#include <map>
#include <string>

#include <stdlib.h>

void	file_to_map(std::fstream &file, std::map<std::string, int> &map, std::string delimiter)
{
	std::string line;
	std::string key;
	std::string value;

	while (getline(file, line))
	{
		// std::cout << "Line: " << line << std::endl;
		// if (line.find("date"))
		// {
		// 	getline(file, line);
		// }	
		key = line.substr(0, line.find(delimiter));
		value = line.substr((line.find(delimiter) + 1), line.length());
		map[key] = atoi(value.c_str());
		// map[key] = std::stoi(value);
		// std::cout << "Key: " << key << " Value: " << value << std::endl;
	}
}

int main(int argc, char **argv)
{
    std::fstream    inFile;
    std::fstream    dataFile;
	std::map<std::string, int> dataBase;
	std::map<std::string, int>:: iterator itr;
	std::map<std::string, int> fileData;

    if (argc != 2)
        return (std::cout << "Bad input. Please enter a filename." << std::endl, 0);
    inFile.open(argv[1]);
	if (!inFile.is_open())
        return (std::cout << "Error: could not open file." << std::endl, 0);
    dataFile.open("testdata.csv");
	if (!dataFile.is_open())
        return (std::cout << "Error: could not open database file." << std::endl, 0);
	file_to_map(dataFile, dataBase, ",");
	file_to_map(inFile, fileData, "|");
	itr = fileData.begin();
	while (itr != fileData.end())
	{
		std::cout << "MAP: " << itr->first << " Value: " << itr->second << std::endl;
		itr++;
	}
	itr = dataBase.begin();
	while (itr != dataBase.end())
	{
		std::cout << "database: " << itr->first << " Value: " << itr->second << std::endl;
		itr++;
	}
	return(0);
}

