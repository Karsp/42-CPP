/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:11 by daviles-          #+#    #+#             */
/*   Updated: 2024/11/05 16:17:15 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#ifndef _ZOMBIE_
# define _ZOMBIE_

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void        setName( std::string name );
        void        announce(void);
        
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
