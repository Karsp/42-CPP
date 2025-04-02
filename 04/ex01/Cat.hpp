/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:45:36 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:45:40 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat& operator=(const Cat& rhs);

		std::string getType() const;
		virtual void	makeSound(void) const;

};

#endif

