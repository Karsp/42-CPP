/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:43:19 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:43:20 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define RESET   "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[0;33m" 

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& rhs);
		
		std::string getType() const;
		void	makeSound(void) const;
};

#endif