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
        void            search_contact();
        std::string     truncateInfo(std::string str);
        bool            is_numeric(const std::string &str);
        PhoneBook();
        ~PhoneBook();
};

#endif
