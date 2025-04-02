/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:59 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:46:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal, public Brain
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		Dog& operator=(const Dog& rhs);

		std::string getType() const;
		virtual void	makeSound(void) const;

};

#endif
