/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:10:31 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/02 15:10:32 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RESET   "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[0;33m" 
class Brain
{
private:
	/* data */
public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain& operator=(const Brain& rhs);
	std::string ideas[100];
};

#endif
