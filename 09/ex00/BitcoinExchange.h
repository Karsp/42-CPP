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
#pragma once
#ifndef _BITCOINEX
# define _BITCOINEX

# include <iostream>
# include <map>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange & operator=(BitcoinExchange const &rhs);
    ~BitcoinExchange();

    int is_valid_date();
    int is_valid_value();
	int closer_date();
    
};


#endif

