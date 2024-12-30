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
		std::string	get_fn(void);
		std::string	get_ln(void);
		std::string	get_nn(void);
		std::string	get_pn(void);
		std::string	get_ds(void);

		void		set_fn(std::string);
		void 		set_ln(std::string);
		void 		set_nn(std::string);
		void 		set_pn(std::string);
		void 		set_ds(std::string);

		void    	print_contact();
		void		print_search_contact();

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;
};

#endif