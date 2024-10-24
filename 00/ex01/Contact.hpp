/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:56:52 by daviles-          #+#    #+#             */
/*   Updated: 2024/10/10 16:56:55 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#ifndef CONTACT_H
# define CONTACT_H

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		int	phone_number;
		std::string darkest_secret;
};

#endif