/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:24:08 by daviles-          #+#    #+#             */
/*   Updated: 2024/10/10 16:24:10 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook
{
    private:
        Contact _contact_list[8];
        int     _list_size;
        int     _next_contact;

    public:
        void            add_contact();
        std::string     get_input(std::string input);
        void            search_contact();
        void            print_contact();
        PhoneBook();
        ~PhoneBook();
};

#endif
