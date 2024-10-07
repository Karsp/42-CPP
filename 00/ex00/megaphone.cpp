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
#include <cstdio>

void    printUpper(char *str)
{
    printf("%s\n",str);
}

int main(int argc, char **argv)
{
    // char    *str;
    // char    *aux;

    (void)argc;
    // while (++argv)
    // {
    //     aux = strjoin(str, argv);
    //     if(!aux)
    // }
    printUpper(argv[1]);
    return (0);
}