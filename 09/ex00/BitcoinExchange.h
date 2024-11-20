/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:20 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/18 15:41:22 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#ifndef _BITCOINEX
# define _BITCOINEX

class BitcoinExchange
{
public:
    BitcoinExchange(/* args */);
    ~BitcoinExchange();
    int is_valid_date();
    
};


#endif

