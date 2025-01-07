/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:59 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/08 14:20:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::fstream infile;
	std::string	line;
	std::string	name = ".replace";
	std::string	strFind;
	std::string	strRepl;
    size_t      found;

	if (argc == 4)
	{
        strFind = argv[2];
        strRepl = argv[3];
		infile.open(argv[1]);
		if (!infile.is_open())
			return (std::cout << "Error reading file. Check permissions or file name." << std::endl, 1);
		std::ofstream newfile ((argv[1] + name).c_str());
		while (getline(infile, line))
		{
			found = line.find(strFind);
			while (found != std::string::npos)
			{
				if (found != std::string::npos)
				{
					line.erase(found, strFind.length());
					line.insert(found, strRepl);
					found = line.find(strFind, found + 1);
				}
				else
					break;
			}
			newfile << line << std::endl;
		}
		newfile.close();
		infile.close();
	}
	else
		std::cout << "Please enter three paramaters. Filename, string 1 (to search), string 2 (to replace)." << std::endl;
	return (0);
}

