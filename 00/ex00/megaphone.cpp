/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:56:19 by daviles-          #+#    #+#             */
/*   Updated: 2024/10/07 13:56:23 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int i;
    int j;
    string  loud;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;        
        return(0);
    }
        j = 1;
    while (argv[j])
    {
        i = 0;
        while (argv[j][i] != '\0')
        {
            loud += toupper(argv[j][i]);
            i++;
        }
        j++;
    }
    cout << loud << std::endl;
    return (0);
}