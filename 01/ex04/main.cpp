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
	std::fstream newfile;
	std::string	line;

	if (argc == 4)
	{
		infile.open(argv[1]);
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				std::cout << line << '\n';
			}
		}

		infile.close();
	}
	else
		std::cout << "Please enter three paramaters. Filename, string 1 (to search), string 2 (to replace)." << std::endl;
	return (0);
}

