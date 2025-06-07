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

int main(int argc, char **argv)
{
    std::fstream    inFile;
	std::multimap<std::string, float>:: iterator itr2;
	std::multimap<std::string, float> inputData;

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
	// btc.printDB();
	try
	{
		btc.fileToMap(inFile, inputData, "|");
		std::cout << ">> The input file has been successfully loaded." << std::endl;

		itr2 = inputData.begin();
		while (itr2 != inputData.end())
		{
			// std::cout << "INPUT MAP: " << itr2->first << " Value: " << itr2->second << std::endl;
			btc.convertBitcoinOnDate(itr2->first, itr2->second);
			++itr2;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Input file parsing failed. Exiting program." << std::endl;

	}
	
	inFile.close();
	return(0);
}

