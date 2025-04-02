/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:36 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:45:40 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "Animal.hpp"

class WrongCat: public Animal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();
		WrongCat& operator=(const WrongCat& rhs);

		std::string getType() const;
		void	makeSound(void) const;

};

#endif

