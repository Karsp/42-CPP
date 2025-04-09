/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:09:32 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/07 16:09:33 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "Default Constructor for AMateria Class called" << RESET << std::endl;

}

AMateria::AMateria(std::string const &type)
{
	std::cout << GREEN << "Overload Constructor for AMateria Class called" << RESET << std::endl;

}
