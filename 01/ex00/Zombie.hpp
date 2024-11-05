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
        Zombie*     newZombie( std::string name );
        void        randomChump( std::string name );
        void        announce(void);
        
    private:
        std::string name;

};

#endif
