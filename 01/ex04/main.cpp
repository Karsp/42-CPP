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
// #include <string> 

int main(int argc, char **argv)
{
	std::fstream infile;
	std::fstream newfile;
	std::string	line;
	std::string	strFind;
	std::string	strRepl;
    size_t      found;

	if (argc == 4)
	{
        strFind = argv[2];
        strRepl = argv[3];
        std::cout << "strFind " << strFind << " strRep " << strRepl << std::endl;
		infile.open(argv[1]);
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				std::cout << "line " <<  line << '\n';
                found = strFind.find(strRepl);
                if (found != std::string::npos)
                {
                    std::cout << "first needle found at:" << found <<  '\n';
                }
                    std::cout << "first needle found at:" << found <<  '\n';
			}
		}

		infile.close();
	}
	else
		std::cout << "Please enter three paramaters. Filename, string 1 (to search), string 2 (to replace)." << std::endl;
	return (0);
}

