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

// void    ft_replace(std::string &line, size_t found, std::string strFind, std::string  strRepl)
// {
//     size_t  size = strFind.length;
//     size_t  i = 0;

//     line.erase(found, size);
//     line.insert(found, strRepl);
// }

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
		infile.open(argv[1]);
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				std::cout << "line " <<  line << '\n';
                found = line.find(strFind);
                while (found != std::string::npos)
                {
                    if (found != std::string::npos)
                    {
                        std::cout << "first needle found at:" << found <<  '\n';
                        line.erase(found, strFind.length());
                        line.insert(found, strRepl);
                        found = line.find(strFind, found + 1);
                    }
                    else
                        break;
                }
				std::cout << "line " <<  line << '\n';
			}
		}

		infile.close();
	}
	else
		std::cout << "Please enter three paramaters. Filename, string 1 (to search), string 2 (to replace)." << std::endl;
	return (0);
}

