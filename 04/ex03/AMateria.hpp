/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:09:25 by daviles-          #+#    #+#             */
/*   Updated: 2025/04/07 16:09:26 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERRIA_HPP
# define AMATERRIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:

    public:
    AMateria(std::string const & type);


    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};


#endif