/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:43:19 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:43:20 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include <iostream>
	#ifndef ANIMAL_HPP
	# define ANIMAL_HPP

	# define RESET   "\033[0m"
	# define BLUE "\033[34m"
	# define GREEN "\033[32m"
	# define RED "\033[31m"
	# define YELLOW "\033[0;33m" 



	class Animal
	{
		protected:
			std::string _type;
		public:
			Animal();
			Animal(const Animal& other);
			virtual ~Animal();
			Animal& operator=(const Animal& rhs);
			
			std::string getType() const;
			virtual void	makeSound(void) const;
	};

	#endif